/*
 * function: func_021BE5D4
 * address: 0x021BE5D4
 * packet: pkt_ov209_021BE5D4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021B93C0 0x021B93C0 thumb ov067
 *   func_021BD8B0 0x021BD8B0 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 */
extern int func_021B93B0(char *);
extern int func_021B93B8(char *);
extern int func_021B93C0(char *);
extern int func_021BD8B0(char *,int);
extern void func_021BD890(char *,int,int);
void func_021BE5D4(char *p,int flag)
{
    int n=func_021B93B0(*(char **)(p+0xc2c));
    if (func_021BD8B0(p,7)!=12 || flag==0) {
        if (func_021B93B8(*(char **)(p+0xc2c))==0 && n==0)
            func_021BD890(p,7,18);
        else func_021BD890(p,7,4);
    }
    if (func_021BD8B0(p,6)!=13 || flag==0) {
        if (func_021B93C0(*(char **)(p+0xc2c))==0 && n==*(int *)(p+0xc34)-1) {
            func_021BD890(p,6,19);
            return;
        }
        else func_021BD890(p,6,5);
    }
}
