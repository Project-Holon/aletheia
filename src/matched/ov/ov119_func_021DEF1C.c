/*
 * function: func_021DEF1C
 * address: 0x021DEF1C
 * packet: pkt_ov119_021DEF1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Nested success tests share the normal callback after the inner
 * guards. The bank allocation reads p+0x5f4 directly; the name allocation
 * reads the saved heap pointer, reproducing the original two load forms.
 * interface: 02019B58 receives the visibly loaded record pointer: its
 * empty 020185F0 call preserves r0 for 02019B64, which reads that input.
 * symbols:
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_02008F88 0x02008F88 thumb
 *   func_02019B58 0x02019B58 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF0B8 0x021DF0B8 thumb ov119
 *   func_021DEEA8 0x021DEEA8 thumb ov119
 *   func_02156ED0 0x02156ED0 thumb ov009
 *   func_02156DC4 0x02156DC4 thumb ov009
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 func_021B99F0(u8 *);
extern u32 func_021B99F4(u32 p, u32 i);
extern void func_021B9774(u8 *);
extern void func_021B99B8(u8 *);
extern void func_021B9838(u8 *);
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
extern int func_021D89EC(const u8 *p);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_0202136C(u16);
extern void *func_02008F08(int);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void func_02019B58(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF0B8(char *p);
extern void func_021DEEA8(void *);
extern void func_02156ED0(void);
extern void func_02156DC4(int a0, int a1);
void func_021DEF1C(u8 *p)
{
    int status, result, i, off1, off2;
    u8 n=0, error;
    u8 *data;
    const u16 *heap;
    void *mon, *bank, *text, *name;
    u32 value;
    status=func_021B99DC(*(u8 **)p);
    result=func_021B9790(*(u8 **)p);
    if(result==0) {
    if(status==200) {
        data=func_021B97F4(*(u8 **)p);
        p[0x11e6]=func_021B99F0(data);
        if(p[0x11e6]==1) {
            off1=0x109a;
            if(*(u16 *)(p+off1)==0) {
                i=n;
                heap=(const u16 *)(p+0x5f4);
                off2=off1;
                off2-=0xb6;
                off1-=0xb6;
                do {
                    if(func_021D89EC(*(void **)(p+i*4+off1))) {
                        mon=*(void **)(p+i*4+off2);
                        if(func_021B99F4((u32)data,n)) {
                            value=func_02017E1C(mon,6,0);
                            bank=func_02045B38(0,2,81,*(u16 *)(p+0x5f4));
                            text=func_02045EC0(bank,15);
                            func_02045C04(bank);
                            if(func_0202136C(value)) {
                                name=func_02008F08(*heap);
                                func_02017E1C(mon,167,(u32)name);
                                func_02008F88(name,func_02045A90(text));
                                func_02017E40(mon,167,(u32)name);
                                func_020307B0(name);
                            }
                            func_02019B58(mon);
                            func_02017E40(mon,142,(u32)func_02045A90(text));
                            func_02045808(text);
                        }
                        n++;
                    }
                    i++;
                } while(i<3);
                *(u16 *)(p+0x109a)=1;
                func_021D8E84(p,(int)func_021DF0B8);
                goto cleanup;
            }
        }
        func_021D8E84(p,(int)func_021DEEA8);
    } else goto failed;
    } else goto failed;
    goto cleanup;
failed:
    {
        if(result==15 || status==200) return;
        switch(status) {
        case 400: error=240; break;
        case 401: error=241; break;
        case 408: error=242; break;
        default: error=255; break;
        }
        p[0x11e6]=error;
        func_021B9774(*(u8 **)p);
    }
    func_021D8E84(p,(int)func_021DEEA8);
cleanup:
    if(*(u8 **)p) {
        func_021B99B8(*(u8 **)p);
        func_021B9838(*(u8 **)p);
        *(u8 **)p=0;
        func_02156ED0();
        func_02156DC4(0,0);
    }
}
