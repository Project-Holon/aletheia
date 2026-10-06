/*
 * function: func_021DCDD8
 * address: 0x021DCDD8
 * packet: pkt_ov183_021DCDD8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * 2026-10-05 (D8 lane19): re-verified, MATCH*; sole blocker is ov186 callee 0x021FD1C4 (no outside witness; needs a label seed). Source is byte-correct; no C change possible.
 * blocker: unlabelled ov186 0x021FD1C4 has no outside witness; large leaf parked by parent
 * extent: two bytes of zero alignment padding at 0x021DCE26
 * symbols:
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 */
typedef unsigned short u16;
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
void func_021DCDD8(char *p, char *q)
{
    int flag;
    if(*(int *)(p+0x44)==0 && *(int *)(p+0xdc)==0) {
        *(int *)(p+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(p+0xd0)+8)==0) flag=0;
        *(void **)(p+0x44)=func_021FD1C4((void *)(*(int *)(p+0xc0)),(char *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x18)),(void *)(*(int *)(p+4)),flag,*(unsigned short *)(p+0xb4));
    }
}
