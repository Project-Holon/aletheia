/*
 * file:     event_poke_status_p25.c
 * unit:     yes
 * function: func_0215AF40, func_0215AF98, func_0215AFE0, func_0215AFF4, func_0215B014, func_0215B028, func_0215B068, func_0215B084, func_0215B0B4, func_0215B104, func_0215B138, func_0215B158, func_0215B190, func_0215B214, func_0215B26C, func_0215B2C4, func_0215B328, func_0215B350, func_0215B378, func_0215B3AC, func_0215B3DC, func_0215B408, func_0215B438, func_0215B464
 * address:  0x0215AF40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D064  0x0200D064  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_0200D0CC  0x0200D0CC  thumb
 *   func_0200CF28  0x0200CF28  thumb
 *   func_0200CA28  0x0200CA28  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CA40  0x0200CA40  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02014314 0x02014314 thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C308 0x0200C308 thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162A74  0x02162A74  thumb  ov010
 *   func_02162708  0x02162708  thumb  ov010
 *   func_02162748  0x02162748  thumb  ov010
 *   func_0215A4EC  0x0215A4EC  thumb  ov010
 *   func_0215A500  0x0215A500  thumb  ov010
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02011290  0x02011290  thumb
 *   func_02012A44 0x02012A44 thumb
 *   func_0216EFA8 0x0216EFA8 thumb ov010
 *   d_02171160 0x02171160 data a2
 */
#include "../../matched/include/Obj17686.h"
#include "../../matched/include/Obj17687.h"

struct Blk37;
struct Ctx;
struct Big;
struct Sub02008700Obj;
struct BigObj;
struct SaveBlock;
struct Sub020089A8Obj;
struct Sub0200852CObj;
struct Blk34;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed int     s32;

extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0200CA1C(void *a);
extern int func_0200D064();
extern int func_0200CED4();
extern u16 func_0200D0CC(struct Blk37 *p);
extern u16 func_0200CF28(struct Blk37 *p);
extern struct Blk37 *func_0200CA28(struct Blk37 *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Blk37 *func_0200CA40(struct Blk37 *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02008428(unsigned short *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_02014314(char *,int);
extern u32 func_0201293C(const struct BigObj *p);
extern void func_02007A68(void *save, u32 bits);
extern void *func_020127A4(struct SaveBlock *p);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 func_02025C88(u32 x);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern struct Sub020089A8Obj *func_02008A00(struct Sub020089A8Obj *obj);
extern void *func_02012F08(int *p);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162A74(int, int, u16, u16, u16);
extern void func_02162708(struct Ctx *c, u32 idx, u16 a, u32 b, u16 e);
extern int func_02162748(int, int, int, u16, int, u16);
extern int func_0215A4EC();
extern int func_0215A500();
extern unsigned func_0215A4D8(void *a, unsigned b);
extern void *func_0215A5F4(void *p);
extern void *func_0215F6E8(void *p);
extern int func_0215898C();
extern int func_02011290();
extern u32 func_02012A44(const struct BigObj *p);
extern int func_0216EFA8(int,int);
int func_0215AF40(int a0, int a1);
int func_0215AF98(int a0, int a1);
int func_0215AFE0(int a0, int a1);
int func_0215AFF4(int a0, int a1);
int func_0215B014(int a0, int a1);
int func_0215B028(int a0, int a1);
int func_0215B068(int a,int b);
int func_0215B084(int a,int b);
int func_0215B0B4(int a0, int a1);
int func_0215B104(int a,int b);
int func_0215B138(void *a0, void *a1);
int func_0215B158(int a,int b);
int func_0215B190(int a0, int a1);
int func_0215B214(int a0, int a1);
int func_0215B26C(int a0, int a1);
int func_0215B2C4(int a0, int a1);
int func_0215B328(int a0, int a1);
int func_0215B350(int a0, int a1);
int func_0215B378(int a0, int a1);
int func_0215B3AC(int a0, int a1);
int func_0215B3DC(int a,int b);
int func_0215B408(int a0, int a1);
int func_0215B438(int a,int b);
int func_0215B464(int a,int b);
extern const u16 d_02171160[];


int func_0215AF40(int a0, int a1)
{
    void *v;
    int k, x;
    u16 *out;
    v = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = (int)func_02159B10((void *)a0, (void *)a1);
    x = (int)func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D064(v, x);
        break;
    case 1:
        *out = func_0200CED4(v, x);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}


int func_0215AF98(int a0, int a1)
{
    void *v;
    int k;
    u16 *out;
    v = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = (int)func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D0CC(v);
        break;
    case 1:
        *out = func_0200CF28(v);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}


int func_0215AFE0(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AFE8:
    p = func_0200CA1C(v0);
loc_0215AFEC:
    a0 = (int)func_0200CA28(p);
loc_0215AFF0:
a0 = 0;
    return a0;}


int func_0215AFF4(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AFFC:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B004:
    p = func_0200CA1C(v0);
loc_0215B008:
    a0 = func_0200CA38(p);
loc_0215B00C:
*q = a0;
a0 = 0;
    return a0;}


int func_0215B014(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B01C:
    p = func_0200CA1C(v0);
loc_0215B020:
    a0 = (int)func_0200CA40(p);
loc_0215B024:
a0 = 0;
    return a0;}


/*
 * blocked:
 */
int func_0215B028(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    void *q;
    struct Sub02008700Obj *t4;
    u16 *dst;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B034:
    p = func_020120F4((const struct Ctx *)v0);
loc_0215B038:
    q = func_02012EBC(p);
loc_0215B03C:
    t4 = func_0200873C(q);
loc_0215B040:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215B04A:
    a0 = func_02008428((short unsigned int *)t4);
loc_0215B052:
    if (a0 == 0) goto loc_0215B05C;
loc_0215B056:
    if (a0 == 1) goto loc_0215B060;
loc_0215B05A:
    goto loc_0215B064;
loc_0215B05C:
a0 = 0;
    goto loc_0215B062;
loc_0215B060:
a0 = 1;
loc_0215B062:
*dst = a0;
loc_0215B064:
a0 = 0;
    return a0;}

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215B068(int a,int b)
{
    func_02014314((char *)func_0201296C(func_0215A5E4((void *)b)), 0x963);
    return 0;
}

int func_0215B084(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    int p = func_0201293C(func_0215A5E4((void *)b));
    if ((u16)(k + 0xFFFF) <= 1) func_02007A68((void *)p,k);
    return 0;
}


int func_0215B0B4(int a0, int a1)
{
    int t4;
    int t6;
    char *sb;
    void *p;
    struct Sub020089A8Obj *obj;
    unsigned short *v0;
    unsigned short *v1;
    void *v2;

t6 = a0 + 0;
t4 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0BE:
a0 = t6 + 0;
a1 = t4 + 0;
    v1 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0C8:
a0 = t4 + 0;
    v2 = func_0215A5E4((void *)a0);
loc_0215B0D0:
    sb = func_020127A4((struct SaveBlock *)v2);
loc_0215B0D6:
    p = func_02012EBC((struct Big *)v2);
loc_0215B0DE:
    obj = func_020089C0(p);
loc_0215B0E2:
sb = sb + 0x20;
    a0 = func_02008554((const struct Sub0200852CObj *)sb);
loc_0215B0EC:
    a0 = func_02025C88(a0);
loc_0215B0F0:
((struct Obj17687 *)((char *)v1))->f0 = a0;
    a0 = func_020089F4(obj);
loc_0215B0F8:
((struct Obj17686 *)((char *)v0))->f0 = a0;
    a0 = (int)func_02008A00(obj);
loc_0215B100:
a0 = 0;
    return a0;}

int func_0215B104(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = (func_0200C308(func_02012F08(func_0215A5E4((void *)b)),k) & 1) != 0;
    return 0;
}


/*
 * The third argument of the arm9 pair call is the slot the overlay index
 * returned, with a literal one alongside.
 */
int func_0215B138(void *a0, void *a1)
{
    void *v = (void *)func_02159B10(a0, a1);

    func_0200C2F0(func_02012F08(func_0215A5E4(a1)), (u32)v, 1);

    return 0;
}

int func_0215B158(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    if (func_0200C308(func_02012F08(func_0215A5E4((void *)b)),k) == 3) *out = 1; else *out = 0;
    return 0;
}

int func_0215B190(int a0, int a1)
{
    void *p = func_0215A5E4((void *)a1);
    int q = func_0201296C(p);
    u16 *out = func_02159AE8((void *)a0, (void *)a1);
    void *t;
    int r;
    if (func_020142E8((void *)q, 0x97B) != 0) {
        t = func_02012EBC((struct Big *)p);
        r = func_0200725C(t, 8, 4);
        switch (r) {
        case 0:
            *out = 0;
            break;
        case 1:
        case 2:
            if (func_0200ECB4(func_020073D8(t, 8, 0)) == 0) {
                *out = 0;
            } else {
                *out = 1;
            }
            break;
        default:
            *out = 2;
            break;
        }
        func_020072A4(t, 8);
    } else {
        *out = 0;
    }
    return 0;
}

int func_0215B214(int a0, int a1)
{
    int v = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162A74(func_02012844(func_0215A5E4((void *)a1)), v, x, y, z);
    return 0;
}

int func_0215B26C(int a0, int a1)
{
    int v = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162708((struct Ctx *)func_02012844(func_0215A5E4((void *)a1)), (int)v, x, (u16)y, z);
    return 0;
}

int func_0215B2C4(int a0, int a1)
{
    int a = (int)func_02159B10((void *)a0, (void *)a1);
    int b = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162748(func_02012844(func_0215A5E4((void *)a1)), a, b, x, y << 16, z);
    return 0;
}


int func_0215B328(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B334:
    a0 = func_0201296C(v0);
loc_0215B338:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B342:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A4EC(a0, a1);
loc_0215B34A:
a0 = 0;
    return a0;}


int func_0215B350(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B35C:
    a0 = func_0201296C(v0);
loc_0215B360:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B36A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A500(a0, a1);
loc_0215B372:
a0 = 0;
    return a0;}


int func_0215B378(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B384:
    a0 = func_0201296C(v0);
loc_0215B388:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B392:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B39C:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_0215A4D8((void *)a0, a1);
loc_0215B3A6:
*q = a0;
a0 = 0;
    return a0;}


int func_0215B3AC(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B3B8:
a0 = t6 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215B3C0:
    p = func_0215F6E8(v0);
loc_0215B3C8:
    a0 = func_0215898C(v1, p);
loc_0215B3D0:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B3D6:
a0 = 1;
    return a0;}

int func_0215B3DC(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int z = 1;
    if (func_0216EFA8(func_02012A44(func_0215A5E4((void *)b)),1) == 1) *out = 0; else *out = z;
    return 0;
}


int func_0215B408(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B414:
a0 = t6 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215B41C:
    p = func_0215F6E8(v0);
loc_0215B424:
    a0 = func_0215898C(v1, p);
loc_0215B42C:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B432:
a0 = 1;
    return a0;}

int func_0215B438(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int z = 0;
    if (func_0216EFA8(func_02012A44(func_0215A5E4((void *)b)),0) == 1) *out = z; else *out = 1;
    return 0;
}

int func_0215B464(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171160[k];
    return 0;
}
