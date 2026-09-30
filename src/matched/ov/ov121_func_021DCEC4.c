/*
 * function: func_021DCEC4
 * address: 0x021DCEC4
 * packet: pkt_ov121_021DCEC4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 */
extern void *func_021D9CA4(int,int,void *,void *,int);
extern void func_021D9FFC(void *,int,int);
extern void func_021D9F08(void *,int,int,int);
extern int func_021D9FF8(void *);
extern void func_021D9E04(void *);
extern void func_021DA8B0(void *,void *);
extern void func_021D9E50(void *);
extern void func_021DC08C(void);
void func_021DCEC4(void *arg,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (!*(void **)(p+0xabc))
            *(void **)(p+0xabc)=func_021D9CA4(0,15,*(void **)(p+0x14),*(void **)(p+0x10),29);
        func_021D9FFC(*(void **)(p+0xabc),1,13);
        func_021D9F08(*(void **)(p+0xabc),*(int *)(p+0x1c),92,1);
        *state=1; break;
    case 1:
        if (func_021D9FF8(*(void **)(p+0xabc))) *state=2;
        break;
    case 2:
        if (*(void **)(p+0xabc)) {
            func_021D9E04(*(void **)(p+0xabc));
            *(void **)(p+0xabc)=0;
        }
        func_021DA8B0(arg,func_021DC08C);
        break;
    }
    if (*(void **)(p+0xabc)) func_021D9E50(*(void **)(p+0xabc));
}
