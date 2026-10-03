/*
 * function: func_021E0A64
 * address: 0x021E0A64
 * packet: pkt_ov119_021E0A64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_02012984 0x02012984 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021DFD64 0x021DFD64 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021E0BA4 0x021E0BA4 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 *   func_021DFD3C 0x021DFD3C thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
struct BigObj;
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void func_021D8E84(void *,int),func_021D9434(void *),func_021DFD64(void *),func_02045CAC(int,int,int),func_021E1024(void *),func_021E1030(void *),func_021E0BA4(void *),func_021E0C78(void *),func_021DFD3C(void *);
void func_021E0A64(char *p)
{
    void *a,*b;
    u32 out,result;
    if(*(int *)(p+0x82c)==0) {
        func_021D8E84(p,(int)func_021E0C78);
        goto exit;
    }
    else {
    if(*(int *)(p+8)!=0) {
        if(func_021D8AA8(p)) {a=func_021D8FA4(p,0);b=func_021D8FA4(p,1);}
        else {a=func_021D8FA4(p,1);b=func_021D8FA4(p,0);}
        result=func_0201B2B0(0,a,1,(u32)b,func_02012984(*(void **)(p+0x82c)),&out,*(u16 *)(p+0x5f4));
        if(result) {
            *(int *)(*(char **)(p+8)+8)=1;
            *(u32 *)(*(char **)(p+8)+12)=result;
            *(u32 *)(*(char **)(p+8)+16)=out;
            func_021D8E84(p,(int)func_021D9434);
            func_021DFD64(p);
            return;
        }
    }
    func_02045CAC(*(int *)(p+0x720),50,*(int *)(p+0x738));
    func_021E1024(p);func_021E1030(p);
    func_021D8E84(p,(int)func_021E0BA4);
    }
exit:
    func_021DFD3C(p);
}
