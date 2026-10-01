/*
 * function: func_021BB4E0
 * address: 0x021BB4E0
 * packet: pkt_ov206_021BB4E0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_021BB534 0x021BB534 thumb ov206
 *   func_021BB79C 0x021BB79C thumb ov206
 *   func_021BB980 0x021BB980 thumb ov206
 */
extern int func_0201AE1C(int,int);
extern void func_021BB534(char *,int,int,int);
extern void func_021BB79C(char *,int,int,int,int);
extern void func_021BB980(char *);
void func_021BB4E0(char *p,int mode,int which)
{
    int mon=*(int *)(p+0x26c);
    unsigned char first=func_0201AE1C(mon,6);
    unsigned char second=func_0201AE1C(mon,7);
    if(first==second) second=17;
    if(mode==6) func_021BB534(p,first,second,which);
    else func_021BB79C(p,first,second,mode,which);
    func_021BB980(p);
}
