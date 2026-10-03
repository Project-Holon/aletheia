/*
 * function: func_021D8FBC
 * address: 0x021D8FBC
 * packet: pkt_ov123_021D8FBC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 * symbols:
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_020092EC 0x020092EC thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D87F8 0x021D87F8 thumb ov123
 *   func_021D8EC4 0x021D8EC4 thumb ov123
 *   func_021D88A0 0x021D88A0 thumb ov123
 *   func_021D5D94 0x021D5D94 thumb ov123
 *   func_021D54F4 0x021D54F4 thumb ov123
 *   func_021D8F3C 0x021D8F3C thumb ov123
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_0203D34C 0x0203D34C arm
 *   d_021DABA4 0x021DABA4 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov114_id[];
extern const char d_021DABA4[];
extern int func_02034AC4(signed int);
extern void func_0203064C(void *,u32,u32);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u8,u32);
struct Big;
struct BigObj;
struct Sub02009448Obj;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern int func_0200853C(void *);
extern u32 func_0201293C(const struct BigObj *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const void *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D87F8(char *);
extern void func_021D8EC4(char *);
extern void func_021D88A0(char *);
extern u8 *func_021B9800(int,int,int);
extern void func_02156DC4(int,int);
extern u8 *func_021D5D94(u32);
extern u8 *func_021D54F4(u32,u32);
extern void func_021D8F3C(char *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_0203D34C(u32,u32);
int func_021D8FBC(void *a,int b,char *q)
{
    char *p;
    int value;
    func_02034AC4((int)ov114_id);
    func_0203064C((void *)1,98,0x88000);
    p=func_0203159C(a,0xb0,98);
    func_02082BCC(p,0,0xb0);
    *(u16 *)p=98;
    if (!q) func_02034714(d_021DABA4,0,d_021DABA4);
    if (q) {
        *(char **)(p+0x20)=q;
        *(void **)(p+0x2c)=*(void **)(q+4);
        *(void **)(p+0x28)=func_02012EBC(*(void **)(q+4));
        value=func_0200853C(func_02012944(*(void **)(q+4)));
        *(u32 *)(p+0x24)=func_0201293C(*(void **)(q+4));
        *(int *)(p+0x48)=*(u16 *)(q+0x1d0);
        *(int *)(p+0x4c)=*(u16 *)(q+0x1d2);
        *(u8 *)(p+0xac)=func_020092EC(func_02009448(*(void **)(p+0x28)));
        *(u8 *)(p+0xaf)=*(u8 *)(p+0xac);
        func_02009448(*(void **)(p+0x28));
        switch (*(u32 *)(q+0x1c8)) {
        case 0:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D87F8,0xa89);
            break;
        case 1:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D8EC4,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D8EC4,0xa91);
            break;
        case 3:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D87F8,0xa95);
            break;
        case 4:
            func_021D6EE0(p,(int)func_021D88A0,0xa98);
            break;
        }
        if (*(int *)(q+0x1c8)!=4) {
            *(void **)(p+0x10)=func_021B9800(98,value,(int)(q+0x54));
            func_02156DC4((int)func_021D8F3C,(int)p);
        }
    }
    *(void **)(p+0x14)=func_021D5D94(*(u16 *)p);
    *(void **)(p+0x18)=func_021D54F4(*(u16 *)p,39);
    func_0202208C(0,1,1,0,6,1,*(u16 *)p);
    func_0203D34C(0,*(u16 *)p);
    return 1;
}
