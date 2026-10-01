/*
 * function: func_021E1BA8
 * address: 0x021E1BA8
 * packet: pkt_ov183_021E1BA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 * symbols:
 *   func_021E11D0 0x021E11D0 thumb ov183
 *   func_021E0E4C 0x021E0E4C thumb ov183
 *   func_021E0E90 0x021E0E90 thumb ov183
 *   func_021E1374 0x021E1374 thumb ov183
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   func_021E1C00 0x021E1C00 thumb ov183
 */
extern void func_021E11D0(char *,int);
extern void func_021E0E4C(char *);
extern void func_021E0E90(char *,int);
extern void func_021E1374(char *,int);
extern void func_021E0D00(char *,int);
extern void func_021E1C00(char *);
void func_021E1BA8(char *p)
{
    switch (*(int *)(p+0x318)) {
    case 0: break;
    case 1:
        func_021E11D0(p,*(int *)(p+0x31c));
        func_021E0E4C(p);
        func_021E0E90(p,1);
        func_021E1374(p,2);
        *(int *)(p+0x318)=255;
        break;
    case 2:
        func_021E0D00(p,*(int *)(p+0x31c));
        func_021E1C00(p);
        break;
    case 255: break;
    }
}
