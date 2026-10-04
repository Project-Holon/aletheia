/*
 * function: func_021C24F0
 * address: 0x021C24F0
 * packet: pkt_ov099_021C24F0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 3064C preserves caller-loaded r2; 3159C returns the live allocator pointer.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203D668 0x0203D668 arm
 *   func_021BCB8C 0x021BCB8C thumb ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200873C 0x0200873C thumb
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BB1A8 0x021BB1A8 thumb ov099
 *   func_021BDE94 0x021BDE94 thumb ov099
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_0203CD98 0x0203CD98 arm
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern void func_0203064C(u32, u32, u32);
extern char *func_0203159C(void *, u32, u32);
extern void func_02082BCC(void *, int, int);
extern void func_0203D668(u32);
extern int func_021BCB8C(void *);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201283C(const struct BigObj *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_021C24D4(char *, int);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_021BB1A8(char *);
extern void func_021BDE94(char *);
extern void func_021BE6F0(char *, int, int);
extern int func_0203CD98(void);
extern void func_021BA7D8(void *p);
extern void func_0203D34C(u32, u32);
int func_021C24F0(void *obj, int unused, char *args)
{
    char *p;
    func_0203064C(1, 0x8021, 0xa4000);
    p = func_0203159C(obj, 0x1360, 0x21);
    func_02082BCC(p, 0, 0x1360);
    func_0203D668((u32)p);
    *(u32 *)(p + 8) = *(u32 *)args;
    *(u32 *)(p + 0xc0) = *(u32 *)(args + 8);
    *(u32 *)(p + 0xc4) = *(u32 *)(args + 4);
    *(int *)(p + 0xcc) = func_021BCB8C(*(void **)(p + 0xc4));
    *(void **)(p + 0xc8) = func_02012934(*(struct BigObj **)(p + 0xc4));
    *(u32 *)(p + 4) = func_0201283C(*(struct BigObj **)(p + 0xc4));
    *(u32 *)(p + 0xd8) = (u32)func_0200873C((void *)(*(u32 *)(args + 8)));
    *(u32 *)(p + 0x1d8) = *(u32 *)(args + 0xc);
    *(int *)(p + 0x135c) = *(u8 *)(args + 0x49);
    if (*(int *)(args + 0xc) == 1) {
        *(int *)(args + 0xc) = 0;
        func_021C24D4(p, 4);
    } else if (*(int *)(args + 0xc) != 0) {
        func_021C24D4(p, 4);
    } else {
        func_021C24D4(p, 1);
    }
    *(int *)(p + 0x1d0) = 0;
    *(int *)(p + 0x1f0) = -1;
    *(char **)(p + 0x248) = args;
    func_020434DC(15, 0);
    func_02043598(15, 0);
    func_021BB1A8(p);
    *(int *)(p + 0x1cc) = 0;
    func_021BDE94(p);
    if (*(int *)(args + 0xc) == 0) func_021BE6F0(p, 1, 2);
    if (func_0203CD98() != 0) {
        func_021BA7D8(p);
        func_0203D34C(1, 0x21);
    }
    return 1;
}
