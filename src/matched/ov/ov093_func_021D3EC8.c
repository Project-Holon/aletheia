/*
 * function: func_021D3EC8
 * address: 0x021D3EC8
 * packet: pkt_ov093_021D3EC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gAiMoveSickCheckPairs 0x021EFFA0 data a1
 *   BTL_CALC_GetMonParamWithHeap 0x021D805C thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a,b; } Pair;
extern Pair gAiMoveSickCheckPairs[];
extern u32 BTL_CALC_GetMonParamWithHeap(void *,u32);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *,int);
int func_021D3EC8(void *s,struct Unk021D62A8 *m) { u32 i; for(i=0;i<7;i++) if(BTL_CALC_GetMonParamWithHeap(s,gAiMoveSickCheckPairs[i].a) && BTL_POKEPARAM_HasSick(m,gAiMoveSickCheckPairs[i].b)) return 1; return 0; }
