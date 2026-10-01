/*
 * unit: yes
 * function: func_021BA4F4,func_021BA514,func_021BA51C,func_021BA524,func_021BA534,func_021BA544
 * address: 0x021BA4F4
 * packet: pkt_ov206_021BA4F4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BBBD8 0x021BBBD8 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 */
extern void func_021BAF50(void *);
extern void func_021BBBD8(void *,int);
extern void func_021BB92C(void *,int);
void func_021BA4F4(char *p)
{
    func_021BAF50(p);
    func_021BBBD8(p,*(int *)(p+400));
    func_021BB92C(p,*(int *)(p+224));
}
void func_021BA514(char *p)
{
    *(int *)(p+88)=1;
}
void func_021BA51C(char *p)
{
    *(int *)(p+92)=1;
}
int func_021BA524(char *p)
{
    int result=0;
    if(*(int *)(p+84)==4) result=1;
    return result;
}
int func_021BA534(char *p)
{
    int result=0;
    if(*(int *)(p+84)==6) result=1;
    return result;
}
void func_021BA544(char *p)
{
    if(*(int *)(p+84)==0) *(int *)(p+84)=1;
}
