#include "minx86dec/state.h"
#include "minx86dec/opcodes.h"

static minx86_read_ptr_t cip;
#include "minx86dec/x86_core_macros.h"

void minx86dec_decode286(struct minx86dec_state *state,struct minx86dec_instruction *ins) {
	register unsigned int patience = 6;
	cip = state->read_ip;
#define core_level 2
#define isdata32 0 /* no 386-style 32-bit */
#define isaddr32 0 /* no 386-style 32-bit */
#define fpu_level 2

	ins->start = state->read_ip;
	ins->opcode = MXOP_UD;
	ins->segment = -1;
	ins->argc = 0;

	/* bring in the core.
	 * don't bitch about ugliness, this avoid maintaining multiple copies of the same code.
	 * and DOSBox does this too to keep it's various "cores" clean, so there. */
	{
#include "x86_core.h"
	}

	/* invalid opcode. step 1 forward */
	if (ins->opcode == MXOP_UD)
		ins->end = state->read_ip = (ins->start + 1);
	else
		ins->end = state->read_ip = cip;
}

