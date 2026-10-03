/*
 * function: func_021B9F1C
 * address: 0x021B9F1C
 * packet: pkt_ov181_021B9F1C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: arm9 0x02048C4C has no witness outside 0x021B9F1C..0x021B9F40.
 * Verified scratch blocker.c with one --arm (no --region), fixed flags: EXACT, 12 bytes.
 * extern void func_020307B0(void *);
 * void func_02048C4C(void *p) { func_020307B0(p); }
 * Blocker symbols: func_020307B0 0x020307B0 arm.
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_02046788 0x02046788 arm
 */
struct Ctx;struct Rec;
extern void func_02048AC4(void *),func_02048C4C(void *),func_020480E4(struct Ctx *,unsigned),func_02047E54(struct Rec *),func_02046788(void);
void func_021B9F1C(char *p){func_02048AC4(*(void **)(p+12));func_02048C4C(*(void **)(p+16));func_020480E4(*(struct Ctx **)(p+8),*(unsigned short *)(p+24));func_02047E54(*(struct Rec **)(p+8));func_02046788();}
