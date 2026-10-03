/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov131_021D4240
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: owner 02012BF8 reads only r1; unused legacy r2/r3 are
 *   omitted after reading its full body. It returns a complete int word.
 *   Constructors consume context and return pointers, proven by full bodies.
 *   Raw addresses and callback/payload casts retain all 32 bits.
 * lever: explicit case 0 plus default keeps the original switch branch.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_0201747C 0x0201747C thumb
 *   func_021D46EC 0x021D46EC thumb ov131
 *   func_021D65D8 0x021D65D8 thumb ov131
 *   func_021D7B00 0x021D7B00 thumb ov131
 *   func_021D96B0 0x021D96B0 thumb ov131
 *   func_021D87E0 0x021D87E0 thumb ov131
 *   func_021D4964 0x021D4964 thumb ov131
 *   func_021D51DC 0x021D51DC thumb ov131
 *   func_021D4FBC 0x021D4FBC thumb ov131
 *   func_021D46E4 0x021D46E4 thumb ov131
 *   func_020056A0 0x020056A0 thumb
 *   func_02082A60 0x02082A60 arm
 *   func_021D5C4C 0x021D5C4C thumb ov131
 *   func_021D697C 0x021D697C thumb ov131
 *   func_021DA6A4 0x021DA6A4 thumb ov131
 *   func_021D911C 0x021D911C thumb ov131
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021D9C3C 0x021D9C3C thumb ov131
 *   func_021D8F50 0x021D8F50 thumb ov131
 *   func_021D7C38 0x021D7C38 thumb ov131
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_020355C4(void);
extern void *func_021D6064(u8 *);
struct Mon;
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_021D46EC(char *);
extern void *func_021D65D8(void *);
extern void *func_021D7B00(void *);
extern u8 *func_021D96B0(u8 *);
extern void *func_021D87E0(void *);
extern void func_021D4964(void *);
extern void func_021D51DC(char *);
extern void func_021D4FBC(char *);
extern void func_021D46E4(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02082A60(const void *,void *,u32);
extern void func_021D5C4C(u8 *);
extern void func_021D697C(u8 *,int *);
extern void func_021DA6A4(void *,void *);
extern void func_021D911C(void *,void *);
extern int func_02012BF8(void *,int);
extern void func_021D9C3C(void *,u8 *);
extern void func_021D8F50(void *,u8 *);
extern void func_021D7C38(void *,u8 *);
extern void func_0203D34C(u32,u32);
int func_021D4240(char *p)
{
    u8 i;
    *(u16 *)(p+0x18)=(*(u8 **)(p+8))[15];
    *(u8 *)(p+0x1a)=255;
    *(u8 *)(p+0x1b)=0;
    *(u32 *)(p+0x20)=*(u32 *)0x02fffc3c;
    *(int *)(p+0x5c)=4;
    *(int *)(p+0x44)=1;
    *(int *)(p+0x48)=0;
    *(int *)(p+0x4c)=0;
    *(int *)(p+0x54)=0;
    *(int *)(p+0xc)=1;
    *(int *)(p+0x25c)=0;
    *(u8 *)(p+0x260)=0;
    *(int *)(p+0x50)=0;
    *(int *)(p+0x1a0)=0;
    *(int *)(p+0x10)=0;
    *(int *)(p+0x14)=0;
    *(u8 *)(p+0x1c)=func_020355C4();
    if ((*(u8 **)(p+8))[13]==3) {
        (*(u8 **)(p+8))[13]=2;
        *(int *)(p+0x14)=1;
    }
    if ((*(u8 **)(p+8))[12]==2) *(void **)(p+0x258)=func_0201747C(func_021D6064((u8 *)p),*(u16 *)p);
    else *(void **)(p+0x258)=0;
    func_021D46EC(p);
    *(void **)(p+0x88)=func_021D65D8(p);
    *(void **)(p+0x8c)=func_021D7B00(p);
    *(void **)(p+0x90)=func_021D96B0((u8 *)p);
    *(void **)(p+0x94)=func_021D87E0(p);
    func_021D4964(p);
    func_021D51DC(p);
    func_021D4FBC(p);
    *(void **)(p+4)=func_020056A0((u32)func_021D46E4,(u32)p,8);
    *(u16 *)(p+0x1a4)=0;
    func_02082A60((void *)0x0500026c,p+0x1a6,12);
    func_02082A60((void *)0x05000360,p+0x1b6,64);
    func_02082A60((void *)0x050003a0,p+0x216,32);
    func_02082A60((void *)0x050003a0,p+0x236,32);
    func_021D5C4C((u8 *)p);
    if ((*(u8 **)(p+8))[13]==2) {
        *(int *)(p+0x58)=3;
        func_021D697C((u8 *)p,*(int **)(p+0x88));
        func_021DA6A4(p,*(void **)(p+0x90));
        func_021D911C(p,*(void **)(p+0x94));
    } else {
        *(int *)(p+0x58)=(*(u8 **)(p+8))[16];
        if (*(int *)(p+0x58)<3) {
            for(i=0;i<3;i++) *(int *)(p+0x60+i*4)=func_02012BF8(*(void **)(*(char **)(p+8)+8),i+7);
        }
        func_021D697C((u8 *)p,*(int **)(p+0x88));
        func_021D911C(p,*(void **)(p+0x94));
        switch (*(int *)(p+0x58)) {
        case 0: func_021D7C38(p,*(u8 **)(p+0x8c)); break;
        case 1: func_021D9C3C(p,*(u8 **)(p+0x90)); break;
        case 2: func_021D8F50(p,*(u8 **)(p+0x94)); break;
        default: *(int *)(p+0x58)=0;
            func_021D7C38(p,*(u8 **)(p+0x8c)); break;
        }
    }
    func_0203D34C(1,*(u16 *)p);
    return 1;
}
