#include "minx86dec/state.h"
#include "minx86dec/opcodes.h"

static minx86_read_ptr_t cip;
#include "minx86dec/x86_core_macros.h"

void minx86dec_decode586pro(struct minx86dec_state *state,struct minx86dec_instruction *ins) {
	unsigned int dataprefix32 = 0,addrprefix32 = 0;
	register unsigned int patience = 6;
	cip = state->read_ip;
#define core_level 5
#define isdata32 ins->data32
#define isaddr32 ins->addr32
#define fpu_level 5
#define pentium 1
#define pentiumpro
#define cpuid

	ins->data32 = state->data32;
	ins->addr32 = state->addr32;
	ins->start = state->read_ip;
	ins->opcode = MXOP_UD;
	ins->segment = -1;
	ins->argc = 0;

	/* this follows the DOSBox style of core implementation by having one
	 * master header file with decoding logic #included with #defines to
	 * enable/disable functions */

	{
#include "x86_core.h"
	}

	/* invalid opcode. step 1 forward (2 if FPU instruction) */
	if (ins->opcode == MXOP_UD) {
		ins->argc = 0;
		if ((*(state->read_ip) & 0xF8) == 0xD8)
			ins->end = state->read_ip = (ins->start + 2);
		else
			ins->end = state->read_ip = (ins->start + 1);
	}
	else {
		ins->end = state->read_ip = cip;
	}
}

