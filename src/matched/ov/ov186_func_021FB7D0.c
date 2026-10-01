/*
 * function: func_021FB7D0
 * address: 0x021FB7D0
 * packet: pkt_ov186_021FB7D0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020458F8 0x020458F8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 */
extern int func_021FB7B0(void *,int);
extern void *func_0201EC64(unsigned short);
extern void func_0201EE0C(void *,int,unsigned,unsigned,int,int);
extern void *func_02045EC0(int,int);
extern unsigned short func_020458F8(void *);
extern void *func_020457B0(unsigned,unsigned short);
extern void func_0201F250(void *,void *,void *);
extern void func_0201ED04(void *);
extern void func_02045808(void *);
void *func_021FB7D0(unsigned *const *p,void *record,int archive,unsigned short heap)
{
    int n,index,ok;
    void *tmp,*src,*result;
    n=func_021FB7B0(record,11);
    ok=0;
    if(n>=1 && n<=4){index=n-1;ok=1;}
    if(ok){
        if((*p)[index]!=0){
            tmp=func_0201EC64((heap&0x7fff)|0x8000);
            func_0201EE0C(tmp,0,(*p+index)[4],(*p+index)[8],1,2);
            src=func_02045EC0(archive,func_021FB7B0(record,3));
            result=func_020457B0(func_020458F8(src)+7,heap);
            func_0201F250(tmp,result,src);
            func_0201ED04(tmp);
            func_02045808(src);
        }else{
            result=func_02045EC0(archive,func_021FB7B0(record,3));
        }
    }else{
        result=func_02045EC0(archive,func_021FB7B0(record,3));
    }
    return result;
}
