#ifndef __MINX86_OPCODES_H
#define __MINX86_OPCODES_H

/* decoded instruction codes */
enum {
/* 0x00-0x03 */
	MXOP_UD=0,		/* undefined opcode. signal INT 6 */
	MXOP_UD_NOP,		/* undefined opcode, but nothing that would cause INT 6 */
	MXOP_NOP,		/* NOP aka XCHG AX,AX */
	MXOP_PUSH,		/* PUSH */
/* 0x04-0x07 */
	MXOP_POP,		/* POP */
	MXOP_MOV,		/* MOV */
	MXOP_ADD,		/* ADD */
	MXOP_OR,		/* OR */
/* 0x08-0x0B */
	MXOP_ADC,		/* ADC */
	MXOP_SBB,		/* SBB */
	MXOP_AND,		/* AND */
	MXOP_SUB,		/* SUB */
/* 0x0C-0x0F */
	MXOP_XOR,		/* XOR */
	MXOP_CMP,		/* CMP */
	MXOP_DAA,		/* DAA */
	MXOP_DAS,		/* DAS */
/* 0x10-0x13 */
	MXOP_AAA,		/* AAA */
	MXOP_AAS,		/* AAS */
	MXOP_INC,		/* INC */
	MXOP_DEC,		/* DEC */
/* 0x14-0x17 */
	MXOP_JO,		/* JO */
	MXOP_JNO,		/* JNO */
	MXOP_JB,		/* JB */
	MXOP_JNB,		/* JNB */
/* 0x18-0x1B */
	MXOP_JZ,		/* JZ */
	MXOP_JNZ,		/* JNZ */
	MXOP_JBE,		/* JBE */
	MXOP_JA,		/* JA */
/* 0x1C-0x1F */
	MXOP_JS,		/* JS */
	MXOP_JNS,		/* JNS */
	MXOP_JP,		/* JP */
	MXOP_JNP,		/* JNP */
/* 0x20-0x23 */
	MXOP_JL,		/* JL */
	MXOP_JGE,		/* JGE */
	MXOP_JLE,		/* JLE */
	MXOP_JG,		/* JG */
/* 0x24-0x27 */
	MXOP_XCHG,		/* XCHG */
	MXOP_TEST,		/* TEST */
	MXOP_LEA,		/* LEA */
	MXOP_ARPL,		/* ARPL */
/* 0x28-0x2B */
	MXOP_BOUND,		/* BOUND */
	MXOP_CLTS,		/* CLTS */
	MXOP_LAR,		/* LAR */
	MXOP_LGDT,		/* LGDT */
/* 0x2C-0x2F */
	MXOP_LIDT,		/* LIDT */
	MXOP_LLDT,		/* LLDT */
	MXOP_LMSW,		/* LMSW */
	MXOP_LSL,		/* LSL */
/* 0x30-0x33 */
	MXOP_LTR,		/* LTR */
	MXOP_SGDT,		/* SGDT */
	MXOP_SIDT,		/* SIDT */
	MXOP_SLDT,		/* SLDT */
/* 0x34-0x37 */
	MXOP_STR,		/* STR */
	MXOP_SMSW,		/* SMSW */
	MXOP_VERR,		/* VERR */
	MXOP_VERW,		/* VERW */
/* 0x38-0x3B */
	MXOP_INS,		/* INS */
	MXOP_OUTS,		/* OUTS */
	MXOP_ENTER,		/* ENTER */
	MXOP_LEAVE,		/* LEAVE */
/* 0x3C-0x3F */
	MXOP_PUSHA,		/* PUSHA */
	MXOP_POPA,		/* POPA */
	MXOP_PUSHAD,		/* PUSHAD */
	MXOP_POPAD,		/* POPAD */
/* 0x40-0x43 */
	MXOP_MOVS,		/* MOVS */
	MXOP_STOS,		/* STOS */
	MXOP_LODS,		/* LODS */
	MXOP_SCAS,		/* SCAS */
/* 0x44-0x47 */
	MXOP_BSF,		/* BSF */
	MXOP_BSR,		/* BSR */
	MXOP_AAM,		/* AAM */
	MXOP_AAD,		/* AAD */
/* 0x48-0x4B */
	MXOP_CALL,		/* CALL */
	MXOP_CALL_FAR,		/* CALL [far] */
	MXOP_ADDPS,		/* ADDPS */
	MXOP_ADDPD,		/* ADDPD */
/* 0x4C-0x4F */
	MXOP_ADDSD,		/* ADDSD */
	MXOP_ADDSS,		/* ADDSS */
	MXOP_ADDSUBPD,		/* ADDSUBPD */
	MXOP_ADDSUBPS,		/* ADDSUBPS */
/* 0x50-0x53 */
	MXOP_ANDPS,		/* ANDPS */
	MXOP_ANDPD,		/* ANDPD */
	MXOP_ANDNPS,		/* ANDPS */
	MXOP_ANDNPD,		/* ANDPD */
/* 0x54-0x57 */
	MXOP_BSWAP,		/* BSWAP */
	MXOP_BT,		/* BT */
	MXOP_BTC,		/* BTC */
	MXOP_BTR,		/* BTR */
/* 0x58-0x5B */
	MXOP_BTS,		/* BTS */
	MXOP_CBW,		/* CBW */
	MXOP_CWDE,		/* CWDE */
	MXOP_CLC,		/* CLC */
/* 0x5C-0x5F */
	MXOP_CLD,		/* CLD */
	MXOP_CLFLUSH,		/* CLFLUSH */
	MXOP_CLI,		/* CLI */
	MXOP_CMC,		/* CMC */
/* 0x60-0x63 */
	MXOP_CMPPS,		/* CMPPS */
	MXOP_CMPPD,		/* CMPPD */
	MXOP_CMPS,		/* CMPS */
	MXOP_CMOVO,		/* 40 CMOVO -------------- CMOVcc set */
/* 0x64-0x67 */
	MXOP_CMOVNO,		/* 41 CMOVNO */
	MXOP_CMOVC,		/* 42 CMOVC */
	MXOP_CMOVNC,		/* 43 CMOVNC */
	MXOP_CMOVZ,		/* 44 CMOVZ */
/* 0x68-0x6B */
	MXOP_CMOVNZ,		/* 45 CMOVNZ */
	MXOP_CMOVBE,		/* 46 CMOVBE */
	MXOP_CMOVA,		/* 47 CMOVA */
	MXOP_CMOVS,		/* 48 CMOVS */
/* 0x6C-0x6F */
	MXOP_CMOVNS,		/* 49 CMOVNS */
	MXOP_CMOVP,		/* 4A CMOVP */
	MXOP_CMOVNP,		/* 4B CMOVNP */
	MXOP_CMOVL,		/* 4C CMOVL */
/* 0x70-0x73 */
	MXOP_CMOVNL,		/* 4D CMOVNL */
	MXOP_CMOVNG,		/* 4E CMOVNG */
	MXOP_CMOVG,		/* 4F CMOVG */
	MXOP_CMPSD,		/* CMPSD */
/* 0x74-0x77 */
	MXOP_CMPSS,		/* CMPSS */
	MXOP_CMPXCHG,		/* CMPXCHG */
	MXOP_CMPXCHG8B,		/* CMPXCHG8B */
	MXOP_BLENDPS,		/* BLENSPS */
/* 0x78-0x7B */
	MXOP_BLENDPD,		/* BLENDPD */
	MXOP_BLENDVPS,		/* BLENDVPS */
	MXOP_BLENDVPD,		/* BLENDVPD */
	MXOP_CRC32,		/* CRC32 */
/* 0x7C-0x7F */
	MXOP_COMISS,		/* COMISS */
	MXOP_COMISD,		/* COMISD */
	MXOP_CPUID,		/* CPUID */
	MXOP_CVTPI2PS,		/* CVTPI2PS */
/* 0x80-0x83 */
	MXOP_CVTPI2PD,		/* CVTPI2PD */
	MXOP_CVTSI2SD,		/* CVTSI2SD */
	MXOP_CVTPS2PI,		/* CVTPS2PI */
	MXOP_CVTPD2PI,		/* CVTPD2PI */
/* 0x84-0x87 */
	MXOP_CVTSD2SI,		/* CVTSD2SI */
	MXOP_CVTPS2PD,		/* CVTPS2PD */
	MXOP_CVTPD2PS,		/* CVTPD2PS */
	MXOP_CVTSD2SS,		/* CVTSD2SS */
/* 0x88-0x8B */
	MXOP_CVTDQ2PS,		/* CVTDQ2PS */
	MXOP_CVTPS2DQ,		/* CVTPS2DQ */
	MXOP_CVTPD2DQ,		/* CVTPD2DQ */
	MXOP_CVTDQ2PD,		/* CVTDQ2PD */
/* 0x8C-0x8F */
	MXOP_CVTTPS2DQ,		/* CVTTPS2DQ */
	MXOP_CVTTPD2DQ,		/* CVTTPD2DQ */
	MXOP_CVTTPS2PI,		/* CVTTPS2PI */
	MXOP_CVTTPD2PI,		/* CVTTPD2PI */
/* 0x90-0x93 */
	MXOP_CVTSI2SS,		/* CVTSI2SS */
	MXOP_CVTSS2SD,		/* CVTSS2SD */
	MXOP_CVTSS2SI,		/* CVTSS2SI */
	MXOP_CVTTSD2SI,		/* CVTTSD2SI */
/* 0x94-0x97 */
	MXOP_CVTTSS2SI,		/* CVTTSS2SI */
	MXOP_CWD,		/* CWD */
	MXOP_CDQ,		/* CDQ */
	MXOP_DIV,		/* DIV */
/* 0x98-0x9B */
	MXOP_DIVPS,		/* DIVPS */
	MXOP_DIVPD,
	MXOP_DIVSD,
	MXOP_DIVSS,
/* 0x9C-0x9F */
	MXOP_DPPS,
	MXOP_DPPD,
	MXOP_EMMS,
	MXOP_EXTRACTPS,
/* 0xA0-0xA3 */
	MXOP_F2XM1,
	MXOP_FABS,
	MXOP_FADD,
	MXOP_FADDP,
/* 0xA4-0xA7 */
	MXOP_FIADD,
	MXOP_FIADDP,
	MXOP_FBLD,
	MXOP_FBSTP,
/* 0xA8-0xAB */
	MXOP_FCHS,
	MXOP_FCLEX,
	MXOP_FNCLEX,
	MXOP_FWAIT,
/* 0xAC-0xAF */
	MXOP_FCMOVB,
	MXOP_FCMOVE,
	MXOP_FCMOVBE,
	MXOP_FCMOVU,
/* 0xB0-0xB3 */
	MXOP_FCMOVNB,
	MXOP_FCMOVNE,
	MXOP_FCMOVNBE,
	MXOP_FCMOVNU,
/* 0xB4-0xB7 */
	MXOP_FCOMI,
	MXOP_FCOMIP,
	MXOP_FUCOMI,
	MXOP_FUCOMIP,
/* 0xB8-0xBB */
	MXOP_FCOS,
	MXOP_FDECSTP,
	MXOP_FDIV,
	MXOP_FDIVP,
/* 0xBC-0xBF */
	MXOP_FIDIV,
	MXOP_FDIVR,
	MXOP_FDIVRP,
	MXOP_FIDIVR,
/* 0xC0-0xC3 */
	MXOP_FFREE,
	MXOP_FICOM,
	MXOP_FICOMP,
	MXOP_FILD,
/* 0xC4-0xC7 */
	MXOP_FINCSTP,
	MXOP_FINIT,
	MXOP_FNINIT,
	MXOP_FIST,
/* 0xC8-0xCB */
	MXOP_FISTP,
	MXOP_FISTTP,
	MXOP_FLD,
	MXOP_FLD1,
/* 0xCC-0xCF */
	MXOP_FLDL2T,
	MXOP_FLDL2E,
	MXOP_FLDPI,
	MXOP_FLDLG2,
/* 0xD0-0xD3 */
	MXOP_FLDLN2,
	MXOP_FLDZ,
	MXOP_FLDCW,
	MXOP_FLDENV,
/* 0xD4-0xD7 */
	MXOP_FMUL,
	MXOP_FMULP,
	MXOP_FIMUL,
	MXOP_FNOP,
/* 0xD8-0xDB */
	MXOP_FPATAN,
	MXOP_FPREM,
	MXOP_FPREM1,
	MXOP_FPTAN,
/* 0xDC-0xDF */
	MXOP_FRNDINT,
	MXOP_FRSTOR,
	MXOP_FSAVE,
	MXOP_FNSAVE,
/* 0xE0-0xE3 */
	MXOP_FSCALE,
	MXOP_FSIN,
	MXOP_FSINCOS,
	MXOP_FSQRT,
/* 0xE4-0xE7 */
	MXOP_FST,
	MXOP_FSTP,
	MXOP_FSTCW,
	MXOP_FNSTCW,
/* 0xE8-0xEB */
	MXOP_FSTENV,
	MXOP_FNSTENV,
	MXOP_FSTSW,
	MXOP_FNSTSW,
/* 0xEC-0xEF */
	MXOP_FSUB,
	MXOP_FSUBP,
	MXOP_FISUB,
	MXOP_FSUBR,
/* 0xF0-0xF3 */
	MXOP_FSUBRP,
	MXOP_FISUBR,
	MXOP_FTST,
	MXOP_FUCOM,
/* 0xF4-0xF7 */
	MXOP_FUCOMP,
	MXOP_FUCOMPP,
	MXOP_FXAM,
	MXOP_FXCH,
/* 0xF8-0xFB */
	MXOP_FXRSTOR,
	MXOP_FXSAVE,
	MXOP_FXTRACT,
	MXOP_FYL2X,
/* 0xFC-0xFF */
	MXOP_FYL2XP1,
	MXOP_HADDPD,
	MXOP_HADDPS,
	MXOP_HLT,
/* 0x100-0x103 */
	MXOP_HSUBPD,
	MXOP_HSUBPS,
	MXOP_IDIV,
	MXOP_IMUL,
/* 0x104-0x107 */
	MXOP_IN,
	MXOP_INSERTPS,
	MXOP_INT,
	MXOP_INTO,
/* 0x108-0x10B */
	MXOP_INVD,
	MXOP_INVLPG,
	MXOP_IRET,
	MXOP_IRETD,
/* 0x10C-0x10F */
	MXOP_JCXZ,
	MXOP_JMP,
	MXOP_JMP_FAR,
	MXOP_LAHF,
/* 0x110-0x113 */
	MXOP_LFENCE,
	MXOP_LDDQU,
	MXOP_LDMXCSR,
	MXOP_LDS,
/* 0x114-0x117 */
	MXOP_LSS,
	MXOP_LES,
	MXOP_LFS,
	MXOP_LGS,
/* 0x118-0x11B */
	MXOP_LOOP,
	MXOP_LOOPE,
	MXOP_LOOPNE,
	MXOP_MASKMOVDQU,
/* 0x11C-0x11F */
	MXOP_MASKMOVQ,
	MXOP_MFENCE,
	MXOP_MONITOR,
	MXOP_MAXPD,
/* 0x120-0x123 */
	MXOP_MAXPS,
	MXOP_MAXSD,
	MXOP_MAXSS,
	MXOP_MINPD,
/* 0x124-0x127 */
	MXOP_MINPS,
	MXOP_MINSD,
	MXOP_MINSS,
	MXOP_MWAIT,
/* 0x128-0x12B */
	MXOP_MOVAPD,
	MXOP_MOVAPS,
	MXOP_MOVBE,
	MXOP_MOVD,
/* 0x12C-0x12F */
	MXOP_MOVDDUP,
	MXOP_MOVDQA,
	MXOP_MOVDQ2Q,
	MXOP_MOVHLPS,
/* 0x130-0x133 */
	MXOP_MOVHPD,
	MXOP_MOVLHPS,
	MXOP_MOVLPD,
	MXOP_MOVLPS,
/* 0x134-0x137 */
	MXOP_MOVQ,
	MXOP_MOVDQU,
	MXOP_MOVQ2DQ,
	MXOP_MOVHPS,
/* 0x138-0x13B */
	MXOP_MOVSHDUP,
	MXOP_MOVMSKPD,
	MXOP_MOVMSKPS,
	MXOP_MOVNTDQA,
/* 0x13C-0x13F */
	MXOP_MOVNTDQ,
	MXOP_MOVNTI,
	MXOP_MOVNTPD,
	MXOP_MOVNTPS,
/* 0x140-0x143 */
	MXOP_MOVNTQ,
	MXOP_MOVSLDUP,
	MXOP_MOVSS,
	MXOP_MOVSX,
/* 0x144-0x147 */
	MXOP_MOVUPD,
	MXOP_MOVUPS,
	MXOP_MOVZX,
	MXOP_MOVSD,
/* 0x148-0x14B */
	MXOP_MPSADBW,
	MXOP_MUL,
	MXOP_MULPS,
	MXOP_MULPD,
/* 0x14C-0x14F */
	MXOP_MULSD,
	MXOP_MULSS,
	MXOP_NEG,
	MXOP_NOT,
/* 0x150-0x153 */
	MXOP_ORPS,
	MXOP_ORPD,
	MXOP_OUT,
	MXOP_POPCNT,
/* 0x154-0x157 */
	MXOP_POPF,
	MXOP_POPFD,
	MXOP_PUSHF,
	MXOP_PUSHFD,
/* 0x158-0x15B */
	MXOP_RCL,
	MXOP_RET,
	MXOP_RETF,
	MXOP_SHL,
/* 0x15C-0x15F */
	MXOP_SHR,
	MXOP_SAR,
	MXOP_SFENCE,
	MXOP_DUMMY_2,
/* 0x160-0x163 */
	MXOP_SETO,		/* JO */
	MXOP_SETNO,		/* JNO */
	MXOP_SETB,		/* JB */
	MXOP_SETNB,		/* JNB */
/* 0x164-0x167 */
	MXOP_SETZ,		/* JZ */
	MXOP_SETNZ,		/* JNZ */
	MXOP_SETBE,		/* JBE */
	MXOP_SETA,		/* JA */
/* 0x168-0x16B */
	MXOP_SETS,		/* JS */
	MXOP_SETNS,		/* JNS */
	MXOP_SETP,		/* JP */
	MXOP_SETNP,		/* JNP */
/* 0x16C-0x16F */
	MXOP_SETL,		/* JL */
	MXOP_SETGE,		/* JGE */
	MXOP_SETLE,		/* JLE */
	MXOP_SETG,		/* JG */
/* 0x170-0x173 */
	MXOP_SHLD,
	MXOP_SHRD,
	MXOP_SHUFPS,
	MXOP_SHUFPD,
/* 0x174-0x177 */
	MXOP_SQRTPS,
	MXOP_SQRTSD,
	MXOP_SQRTSS,
	MXOP_STC,
/* 0x178-0x17B */
	MXOP_STD,
	MXOP_STI,
	MXOP_STMXCSR,
	MXOP_RCR,
/* 0x17C-0x17F */
	MXOP_SUBPD,
	MXOP_SUBPS,
	MXOP_SUBSD,
	MXOP_SUBSS,
/* 0x180-0x183 */
	MXOP_SYSCALL,
	MXOP_SYSENTER,
	MXOP_SYSEXIT,
	MXOP_SYSRET,
/* 0x184-0x187 */
	MXOP_UCOMISS,
	MXOP_UCOMISD,
	MXOP_UD2,
	MXOP_WBINVD,
/* 0x188-0x18B */
	MXOP_WRMSR,
	MXOP_XADD,
	MXOP_XGETBV,
	MXOP_XLAT,
/* 0x18C-0x18F */
	MXOP_XORPS,
	MXOP_XORPD,
	MXOP_XRSTOR,
	MXOP_XSAVE,
/* 0x190-0x193 */
	MXOP_XSETBV,
	MXOP_PXOR,
	MXOP_UNPCKLPS,
	MXOP_UNPCKLPD,
/* 0x194-0x197 */
	MXOP_UNPCKHPS,
	MXOP_UNPCKHPD,
	MXOP_ROUNDPS,
	MXOP_ROUNDPD,
/* 0x198-0x19B */
	MXOP_ROUNDSS,
	MXOP_ROUNDSD,
	MXOP_RSM,
	MXOP_SAHF,
/* 0x19C-0x19F */
	MXOP_RSQRTPS,
	MXOP_RSQRTSS,
	MXOP_RDTSC,
	MXOP_RDMSR,
/* 0x1A0-0x1A3 */
	MXOP_RDPMC,
	MXOP_RDTSCP,
	MXOP_RCPPS,
	MXOP_RCPSS,
/* 0x1A4-0x1A7 */
	MXOP_INVEPT,
	MXOP_INVVPID,
	MXOP_VMCLEAR,
	MXOP_VMCALL,
/* 0x1A8-0x1AB */
	MXOP_VMLAUNCH,
	MXOP_VMRESUME,
	MXOP_VMPTRLD,
	MXOP_VMPTRST,
/* 0x1AC-0x1AF */
	MXOP_VMREAD,
	MXOP_VMWRITE,
	MXOP_VMXOFF,
	MXOP_VMXON,
/* 0x1B0-0x1B3 */
	MXOP_POR,
	MXOP_PREFETCHNTA,
	MXOP_PREFETCHT0,
	MXOP_PREFETCHT1,
/* 0x1B4-0x1B7 */
	MXOP_PREFETCHT2,
	MXOP_SWAPGS,
	MXOP_PABSB,
	MXOP_PABSW,
/* 0x1B8-0x1BB */
	MXOP_PABSD,
	MXOP_PADDB,
	MXOP_PADDW,
	MXOP_PADDD,
/* 0x1BC-0x1BF */
	MXOP_PADDSB,
	MXOP_PADDSW,
	MXOP_PADDUSB,
	MXOP_PADDUSW,
/* 0x1C0-0x1C3 */
	MXOP_PCMPEQB,
	MXOP_PCMPEQW,
	MXOP_PCMPEQD,
	MXOP_PCMPGTB,
/* 0x1C4-0x1C7 */
	MXOP_PCMPGTW,
	MXOP_PCMPGTD,
	MXOP_PCMPESTRM,
	MXOP_PCMPESTRI,
/* 0x1C8-0x1CB */
	MXOP_PCMPISTRM,
	MXOP_PCMPISTRI,

	MXOP_LAST
};

#endif /* */

