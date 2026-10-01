/*
 * function: func_021BA64C
 * address: 0x021BA64C
 * packet: pkt_ov206_021BA64C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 *   func_021BB4E0 0x021BB4E0 thumb ov206
 *   func_021BBDA8 0x021BBDA8 thumb ov206
 *   func_021BAA4C 0x021BAA4C thumb ov206
 *   func_021BACB0 0x021BACB0 thumb ov206
 */
extern void func_021BAF50(char *);
extern void func_021BB92C(char *,int);
extern void func_021BB4E0(char *,int,int);
extern void func_021BBDA8(char *,int);
extern void func_021BAA4C(char *);
extern void func_021BACB0(char *,int);
void func_021BA64C(char *p,int mode)
{
    if (*(int *)(p+0xe0)) *(int *)(p+0xe0)=0;
    else *(int *)(p+0xe0)=1;
    func_021BAF50(p);
    func_021BB92C(p,*(int *)(p+0xe0));
    func_021BB4E0(p,mode,*(int *)(p+0xe0));
    func_021BBDA8(p,*(int *)(p+8));
    if(mode==6 || *(unsigned short *)(p+0xc)>493) func_021BAA4C(p);
    else func_021BACB0(p,mode);
}
