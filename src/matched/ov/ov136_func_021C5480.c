/*
 * function: func_021C5480
 * address: 0x021C5480
 * packet: pkt_ov136_021C5480
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02008FEC 0x02008FEC thumb
 *   func_02031324 0x02031324 arm
 */
typedef unsigned char u8;
extern void func_0203064C(int,int,int);
extern void *func_0203159C(void *,int,int);
extern void func_02082AC0(int,void *,int);
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02031324(int);
int func_021C5480(void *a, int unused, void **arg)
{
    u8 *p;
    func_0203064C(1,101,65536);
    p = func_0203159C(a,52,101);
    func_02082AC0(0,p,52);
    *(void **)(p+4) = arg;
    *(void **)p = func_02008FEC(*arg);
    *(int *)(p+40) = 8;
    *(int *)(p+44) = 0;
    *(void **)(p+48) = func_02031324(101);
    return 1;
}
