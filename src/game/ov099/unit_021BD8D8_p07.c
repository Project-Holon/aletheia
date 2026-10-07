/*
 * file:     unit_021BD8D8_p07.c
 * unit:     yes
 * function: func_021BE7EC, func_021BE900, func_021BE904, func_021BE94C, func_021BE96C, func_021BE9C8, func_021BEAEC, func_021BEB68, func_021BEBE8, func_021BEC60, func_021BED08, func_021BED3C, func_021BEDA0, func_021BEE64, func_021BEE94, func_021BEEBC, func_021BF000
 * address:  0x021BE7EC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   func_021B9B00 0x021B9B00 thumb ov099
 *   func_02009918 0x02009918 thumb
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0203D210 0x0203D210 arm
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_0202208C 0x0202208C thumb
 *   func_021BE26C 0x021BE26C thumb ov099
 *   func_0204A698 0x0204A698 arm
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   func_020414AC 0x020414AC arm
 *   func_020490F4 0x020490F4 arm
 *   func_021BE53C 0x021BE53C thumb ov099
 *   func_02049238 0x02049238 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021BB050 0x021BB050 thumb ov099
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_0203C8A8 0x0203C8A8 arm
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_0203C600 0x0203C600 arm
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_0203CB00 0x0203CB00 arm
 *   func_0203C3EC 0x0203C3EC arm
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02156C98 0x02156C98 thumb ov009
 *   func_0201A570 0x0201A570 thumb
 *   func_0203C628 0x0203C628 arm
 *   func_0203C5EC 0x0203C5EC arm
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_0203C554 0x0203C554 arm
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BAB04 0x021BAB04 thumb ov099
 *   func_02009A34 0x02009A34 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_021C27D0  0x021C27D0  thumb  ov099
 *   func_021C27D8  0x021C27D8  thumb  ov099
 *   func_02155664 0x02155664 thumb ov009
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C0290 0x021C0290 thumb ov099
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02009A54 0x02009A54 thumb
 *   func_021B95A0 0x021B95A0 thumb ov099
 *   func_021B9900 0x021B9900 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_021C1A58 0x021C1A58 thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C205C 0x021C205C thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../../matched/include/Obj07955.h"
#include "../../matched/include/Obj10207.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj10208.h"
#include "../../matched/include/Obj02802.h"
#include "../../matched/include/Obj13699.h"
#include "../../matched/include/Obj01051.h"
#include "../../matched/include/Obj02156.h"
#include "../../matched/include/Obj18261.h"

struct Sub020097BCObj;
struct Descriptor;
struct Obj;
struct CharBuf;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32_021BE7EC;

typedef struct { u8 low : 2; u8 flag : 2; u8 high : 4; } Flags;

typedef unsigned int u32_021BE904;

typedef unsigned short u16;

typedef unsigned long  u32_021BE94C;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BE96C;

typedef unsigned int u32_021BE9C8;

typedef unsigned int   u32_021BEC60;

typedef unsigned int u32_021BED3C;

typedef unsigned int   u32_021BEDA0;

typedef unsigned long  u32_021BEE64;

typedef unsigned int u32_021BEE94;

typedef unsigned int   u32_021BEEBC;

extern int func_021C23B8(int i);
extern u32_021BE7EC func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern unsigned char func_021C23C0(void *a);
extern int func_021C27E0(void *);
extern void *func_021BE2A8(char *, int);
extern int func_021BDDA8(int);
extern void func_021B9B00(void *, char *, u8);
extern void func_02009918(struct Sub020097BCObj *obj, u32_021BE7EC i, u32_021BE7EC field, u32_021BE7EC value);
extern u32_021BE904 func_020362DC(void);
extern int func_021BA8BC(void *p);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);
extern u32_021BE96C func_021BA858(char *p);
extern int func_0203CEAC(int a0);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BA8EC(char *);
extern u32_021BE9C8 func_0203D210(void);
extern int func_021B96CC(int *);
extern void func_0202208C(void *, u32_021BE9C8, u32_021BE9C8, u32_021BE9C8, u32_021BE9C8, u32_021BE9C8, u32_021BE9C8);
extern void func_021BE26C(char *);
extern void func_0204A698(void);
extern int func_021C1A44(char *);
extern void func_021C1AC0(char *);
extern void func_020414AC(u32_021BE9C8);
extern void *func_020490F4(u32_021BE9C8 id, u32_021BE9C8 heap);
extern void func_021BE53C(char *p, int v);
extern void func_02049238(void *);
extern u32_021BE9C8 func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32_021BE9C8 func_0201F868(void *p);
extern void func_02082BCC(void *, u32_021BE9C8, u32_021BE9C8);
extern void func_021BB050(void *);
extern void func_021BDD0C(void *, int);
extern void func_0203C8A8(void);
extern unsigned char func_02156C84(void);
extern int func_0203C600(void);
extern void func_021BE6F0(char *, int, int);
extern int func_021BE788(char *);
extern int func_021BE4F0(char *, int);
extern int func_0203CB00(void);
extern int func_0203C3EC(void);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_02156C98(int v);
extern void func_0201A570(void *);
extern int func_0203C628(void);
extern int func_0203C5EC(void);
extern u32_021BEC60 func_0203D1C0(u32_021BEC60 index);
extern void func_0203C554(u32_021BEC60 a);
extern unsigned int func_0202EB0C(void);
extern void func_021BAB04(void *p, int message);
extern u32_021BED3C func_02009A34(struct Sub020097BCObj *obj);
extern void func_02049B40(u32_021BEDA0 a, u32_021BEDA0 b, u32_021BEDA0 c, u32_021BEDA0 d, u32_021BEDA0 e, u16 f);
extern u32_021BEDA0 func_020450F0(u32_021BEDA0 layer, u32_021BEDA0 a, u32_021BEDA0 b, u32_021BEDA0 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern int func_021C27D0(void *p);
extern int func_021C27D8(void *p);
extern void func_02155664(void (*callback)(void));
extern void func_021C19A8(char *);
extern void func_021C0290(char *);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32_021BEEBC func_02009A54(struct Sub020097BCObj *obj);
extern void func_021B95A0(char *p, int heap, u32_021BEEBC x2, u32_021BEEBC x3, u32_021BEEBC a4, u32_021BEEBC a5, u32_021BEEBC a6, u32_021BEEBC a7);
extern u8 *func_021B9900(u8 *p, int v);
extern void func_021BE21C(char *,void *);
extern void func_021C1A58(char *,int,int);
extern int func_021C282C(u8 *p);
extern void func_021C205C(u8 *p, int v);
extern void func_021BDE30(void *,int,int);
extern void func_021C2408(char *);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
int func_021BE7EC(char *p);
void func_021BE900(char *p);
int func_021BE904(char *p, int v);
int func_021BE94C(char *p, int v);
int func_021BE96C(char *p, int v);
int func_021BE9C8(char *p, int v);
int func_021BEAEC(char *p, int ret);
int func_021BEB68(char *p, int ret);
int func_021BEBE8(char *p, int result);
int func_021BEC60(char *p, int ret);
int func_021BED08(char *p,int ret);
int func_021BED3C(char *p, int ret);
void func_021BEDA0(char *p);
BOOL func_021BEE64(void *a, char *b);
int func_021BEE94(u32_021BEE94 p, int a);
void func_021BEEBC(char *p);
int func_021BF000(char *p,int ret);

/*
 * lever: byte bitfield preserves the original left/right shift extraction; declaration order preserves local stack slots.
 * prototypes: C23B8 own tail forwarder void(void) preserves loaded index and live pointer return; C23C0 own void forwarder leaves R0 live for the original test; BDD48/BDD54 own u8 returns are widened to preserve original explicit result truncations.
 */
int func_021BE7EC(char *p)
{
    int count = 0;
    int i;
    char *s, *h;
    u8 a, b;
    int old, next;
    for (i = 0; i < 32; i++) {
        s = (char *)func_021C23B8(i);
        a = (u8)func_021BDD48(p, s);
        b = (u8)func_021BDD54(p, s);
        if (func_021C23C0((void *)i) == 0) a = 0;
        if (a != *(u8 *)(p + i + 0x50) ||
            b != *(u8 *)(p + i + 0x70) ||
            *(u8 *)(p + i + 0x90) != func_021C27E0(s)) {
            h = func_021BE2A8(p, i + 1);
            if (h != 0) {
                old = func_021BDDA8(*(u8 *)(p + i + 0x50));
                next = func_021BDDA8(a);
                if (old == 1 && next == 0) func_021B9B00(p + 0x274, h, 0);
                else if (old == 0 && next == 1) func_021B9B00(p + 0x274, h, 1);
                func_02009918(((struct Obj07955 *)p)->f4, i, 8, ((struct Obj10207 *)s)->f14);
                func_02009918(((struct Obj07955 *)p)->f4, i, 9, ((Flags *)(s + 0x1b))->flag);
                func_02009918(((struct Obj07955 *)p)->f4, i, 1, ((struct Obj10207 *)s)->f0);
                func_02009918(((struct Obj07955 *)p)->f4, i, 0, ((struct Obj10207 *)s)->f4);
            }
            *(u8 *)(p + i + 0x50) = a;
            *(u8 *)(p + i + 0x70) = b;
            *(u8 *)(p + i + 0x90) = func_021C27E0(s);
            count++;
        }
    }
    return count;
}

/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021BE900(char *p)
{
}


int func_021BE904(char *p, int v)
{
    int n = *(int *)(p + 0x1E0);
    if (n > 0) {
        *(int *)(p + 0x1E0) = n - 1;
        return v;
    }
    if (func_020362DC() & 3) {
        *(int *)(p + 0x19C) = func_021BA8BC((void *)(*(int *)(p + 0x19C)));
        func_021BAAB8(p, 0x37, 0);
        *(int *)(p + 0x1CC) = 2;
    }
    return v;
}


/*
 * Runs the setup and stamps selector 3 when the guard answers true.
 */
int func_021BE94C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        *(u32_021BE94C *)&((struct Obj00008 *)p)->f1CC = 3;
    }

    return v;
}

/*
 * extent: two trailing zero padding bytes at 0x021BE9C6.
 */
int func_021BE96C(char *p, int v)
{
    int t;
    int zero;
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        func_0203CEAC(0);
        func_021C18C8(p, 1, 2);
        ((struct Obj10208 *)p)->f1CC = 4;
    } else {
        func_021C18C8(p, 1, 2);
        zero = 0;
        func_0203CEAC(0);
        ((struct Obj10208 *)p)->f1D0 = zero;
        ((struct Obj10208 *)p)->f1CC = 0x1a;
    }
    func_021BA8EC(p);
    return v;
}

int func_021BE9C8(char *p, int v)
{
    void *h;
    if (func_0203D210() == 0) {
        if (func_021B96CC((int *)(p + 0x274)) == 1) {
            func_0202208C(0, 0, 0, 0, 6, 1, 0x21);
            func_021BE26C(p);
            func_0204A698();
        }
        if (func_021C1A44(p) == 1) func_021C1AC0(p);
        ((struct Obj02802 *)p)->f198 = (void *)func_021BA8BC(((struct Obj02802 *)p)->f198);
        func_020414AC(3);
        h = func_020490F4(0x21, 0x21);
        func_021BE53C(p, (int)h);
        func_02049238(h);
        ((struct Obj02802 *)p)->f1328 = 1;
        if (((struct Obj02802 *)p)->fB0 != 0) {
            func_020452E8(((struct Obj02802 *)p)->f1A0);
            func_0202020C(((struct Obj02802 *)p)->fB4, 0, 0);
            ((struct Obj02802 *)p)->fB4 = 0;
            func_0201F868(((struct Obj02802 *)p)->fB0);
            ((struct Obj02802 *)p)->fB0 = 0;
        }
        func_02082BCC(p + 0x10, 0, 0x20);
        func_02082BCC(p + 0x30, 0, 0x20);
        func_02082BCC(p + 0x50, 0, 0x20);
        func_02082BCC(p + 0x70, 0, 0x20);
        func_02082BCC(p + 0x90, 0, 0x20);
        func_021BB050(p);
        func_021BDD0C(p, 0);
        func_0203C8A8();
        func_021BAAB8(p, 0x17, 1);
        ((struct Obj02802 *)p)->f1CC = 5;
    }
    return v;
}

int func_021BEAEC(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_02156C84()) {
        *(int *)(p + 0x1cc) = 0x3c;
        func_021BAAB8(p, 0x1e, 1);
    }
    if (func_0203C600()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else {
        if (func_0203CB00() || func_0203C3EC() == 3) func_021BE900(p);
    }
    return ret;
}

/*
 * extent: 126 bytes code followed by two zero alignment bytes.
 *   extern char *d_021469DC;
 *   extern void func_0203C0F4(void);
 *   int func_0203C600(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)func_0203C0F4;
 *   }
 *   extern char *d_021469DC;
 *   extern void func_0203CADC(void);
 *   int func_0203CB00(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)func_0203CADC) return 1;
 *       }
 *       return 0;
 *   }
 */
int func_021BEB68(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_02156C84()) {
        func_02012DAC((int)(*(void **)(p + 0xc4)));
        *(int *)(p + 0x1cc) = 0x3e;
        return ret;
    }
    if (func_0203C600()) {
        if (*(int *)(p + 0x1e8)) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else {
        if (func_0203CB00() || func_0203C3EC() == 3) func_021BE900(p);
    }
    return ret;
}

int func_021BEBE8(char *p, int result)
{
    int v;
    if (func_02156C84()) {
        v = func_02012DD0(*(u8 **)(p + 0xc4));
        switch (v) {
        default:
            func_02156C98(v);
            break;
        case 0:
        case 1:
            return result;
        }
    }
    if (func_0203C600()) {
        if (*(int *)(p + 0x1e8) != 0) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else if (func_0203CB00() || func_0203C3EC() == 3) {
        func_021BE900(p);
    }
    return result;
}

int func_021BEC60(char *p, int ret)
{
    if (*(int *)(p + 0x1e0) > 0) {
        *(int *)(p + 0x1e0) -= 1;
        return ret;
    }
    if (*(void **)(p + 0x1344)) {
        func_0201A570(*(void **)(p + 0x1344));
        *(void **)(p + 0x1344) = 0;
    }
    if (func_0203CB00() || func_0203C3EC() == 3) {
        func_021BE900(p);
    } else {
        if (func_0203C628()) {
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
            goto done;
        } else {
            if (func_0203C3EC() < 4 && !func_0203C5EC() && func_0203D1C0(0xff)) goto done;
            func_0203C554(1);
            if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
        }
        *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
    }
done:
    return ret;
}

/*
 * Extent ends with two-byte alignment padding at 0x021BED3A.
 */
int func_021BED08(char *p,int ret) {
 func_021BA8EC(p);
 if (func_0202EB0C()) func_021BAB04(p,44);
 else func_021BAB04(p,19);
 ((struct Obj13699 *)p)->f1CC=8;
 ((struct Obj13699 *)p)->f1E8=0;
 return ret;
}

int func_021BED3C(char *p, int ret)
{
    if (func_020362DC() & 3) {
        if (!func_02009A34(((struct Obj01051 *)p)->f4)) {
            func_021BAAB8(p, 0x1a, 1);
            ((struct Obj01051 *)p)->f1CC = 0x33;
            ((struct Obj01051 *)p)->f1E0 = 1;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            ((struct Obj01051 *)p)->f1CC = func_021BE4F0(p, 0);
            ((struct Obj01051 *)p)->f19C = (void *)func_021BA8BC(((struct Obj01051 *)p)->f19C);
        }
    }
    return ret;
}

void func_021BEDA0(char *p)
{
    if (((struct Obj02156 *)p)->f194) func_020452E8(((struct Obj02156 *)p)->f194);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x21);
    ((struct Obj02156 *)p)->f198 = (void *)func_021BA8BC(((struct Obj02156 *)p)->f198);
    ((struct Obj02156 *)p)->f194 = (void *)func_020450F0(3, 1, 1, 0x1c, 2, 0xf, 1);
    ((struct Obj02156 *)p)->f198 = (void *)func_020450F0(2, 1, 1, 0x1c, 2, 0xf, 1);
    func_02043B5C(func_02045770(((struct Obj02156 *)p)->f194), 0xff);
    func_02045334(((struct Obj02156 *)p)->f194);
    func_02043B5C(func_02045770(((struct Obj02156 *)p)->f198), 0xff);
    func_02045334(((struct Obj02156 *)p)->f198);
    func_0201F73C(((struct Obj02156 *)p)->f198, 1, (u16)(((struct Obj02156 *)p)->f1334), 0xe);
}


/*
 * True when the two objects - the one at +0x08 of b and the one func_021C23B8
 * returns - agree under func_021C27D8 after both have been released through
 * func_021C27D0.
 */
BOOL func_021BEE64(void *a, char *b)
{
    void *x = ((struct Obj18261 *)b)->f8;
    void *y = (void *)func_021C23B8((int)a);

    func_021C27D0(x);
    func_021C27D0(y);

    if (func_021C27D8(x) == func_021C27D8(y)) {
        return 1;
    }

    return 0;
}

int func_021BEE94(u32_021BEE94 p, int a) {
    if (!func_0203CB00() && !func_0203C628()) return a;
    *(u32_021BEE94 *)(p+460) = 10;
    return a;
}

/*
 * lever: a named enabled result before kind initialization preserves call/store scheduling.
 */
void func_021BEEBC(char *p)
{
    void *h;
    int kind, enabled;
    func_02155664((void (*)(void))func_021BEE64);
    h=func_020490F4(33,33);
    func_021C19A8(p);
    func_021C0290(p);
    func_02082BCC(p+0x30,0,32);
    if(((struct Obj00008 *)p)->fB0){
        func_020452E8(((struct Obj00008 *)p)->f1A0);
        func_0202020C(((struct Obj00008 *)p)->fB4,0,0);
        ((struct Obj00008 *)p)->fB4=0;
        func_0201F868(((struct Obj00008 *)p)->fB0);
        ((struct Obj00008 *)p)->fB0=0;
    }
    if(!func_021B96CC((int *)(p+0x274))){
        enabled=func_02008550((const struct Sub0200852CObj *)func_02012944(((struct Obj00008 *)p)->fC4));
        kind=16;
        if(enabled)kind=17;
        ((struct Obj00008 *)p)->f132A=func_02009A54(((struct Obj00008 *)p)->f4);
        func_021B95A0(p+0x274,33,(u32_021BEEBC)h,kind,((struct Obj00008 *)p)->f132A,33,(u32_021BEEBC)(((struct Obj00008 *)p)->f110),(u32_021BEEBC)(((struct Obj00008 *)p)->f114));
        func_021BE21C(p,func_021B9900((u8 *)(p+0x274),kind));
    }
    if(!func_021C1A44(p))func_021C1A58(p,(int)h,33);
    func_021C282C(((struct Obj00008 *)p)->f8);
    ((struct Obj00008 *)p)->f1351=0;
    func_021C205C((u8 *)p,33);
    func_021BA8EC(p);
    func_021BE788(p);
    func_021BEDA0(p);
    func_021BDD0C(p,0);
    ((struct Obj00008 *)p)->f1F0=-1;
    func_02049238(h);
    func_0202208C(0,1,1,0,6,1,33);
}

int func_021BF000(char *p,int ret) {
 func_021BEEBC(p);
 func_021C18C8(p,1,2);
 func_021BDE30(p,1,2);
 ((struct Obj00008 *)p)->f1CC=11;
 func_021C2408(p);
 func_0203D7B0(0);
 func_0203D7BC(0);
 return ret;
}
