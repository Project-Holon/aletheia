/*
 * function: func_02184798
 * address: 0x02184798
 * packet: pkt_ov219_02184798
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02185E00 0x02185E00 data a4
 *   func_02035C08 0x02035C08 arm
 *   func_021848F4 0x021848F4 thumb ov219
 */
extern const char d_02185E00[];
extern int func_02035C08(const void *);
extern void func_021848F4(const char *,int,int,int *,int *,int *,int *);
void func_02184798(char *p)
{
    int flag=0;
    int result;
    int xf,dx,yf,dy;
    *(int *)(p+0xc320)=0;
    result=func_02035C08(d_02185E00);
    if(result==0)flag=0x400;
    else if(result==1)flag=2;
    if(*(int *)(p+0xc35c)!=0){
        if(flag!=0){*(int *)(p+0xc320)=flag;return;}
        *(int *)(p+0xc324)=0;
        *(int *)(p+0xc330)=0;
        *(int *)(p+0xc334)=0;
        *(int *)(p+0xc338)=0;
        *(int *)(p+0xc320)=0;
        *(int *)(p+0xc328)=*(int *)(p+0xc364);
        *(int *)(p+0xc32c)=*(int *)(p+0xc368);
        *(int *)(p+0xc338)=4;
    }
    if(*(int *)(p+0xc360)!=0){
        switch(*(int *)(p+0xc324)){
        case 0:
            if(*(int *)(p+0xc338)==0)(*(int *)(p+0xc324))++;
            else (*(int *)(p+0xc338))--;
        case 1:
            if(flag!=0)return;
            func_021848F4(p,*(int *)(p+0xc328),*(int *)(p+0xc32c),&xf,&dx,&yf,&dy);
            *(int *)(p+0xc320)=xf|yf;
            *(int *)(p+0xc330)=dx;
            *(int *)(p+0xc334)=dy;
            *(int *)(p+0xc328)=*(int *)(p+0xc364);
            *(int *)(p+0xc32c)=*(int *)(p+0xc368);
            return;
        default:return;
        }
    }else{
        if(flag==0 && *(int *)(p+0xc338)!=0 && *(int *)(p+0xc330)<4 && *(int *)(p+0xc334)<4)
            *(int *)(p+0xc320)=1;
        *(int *)(p+0xc324)=0;
        *(int *)(p+0xc330)=0;
        *(int *)(p+0xc334)=0;
        *(int *)(p+0xc338)=0;
    }
}
