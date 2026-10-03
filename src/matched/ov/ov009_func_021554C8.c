/*
 * function: func_021554C8
 * address:  0x021554C8
 * packet:   pkt_ov009_021554C8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * checks: 1 SDK bodies confirm arities and payloads, case6 returns observed r0=0x3EF; 2 ov009 neighbours no complete twin; 3 u16/u8 flag both unchanged DIFF10; 4 block-local u16 name[2]={0,0} fixes address lifetime, MATCH384; 5 fresh idioms/neighbours and stack-storage idiom reread.
 * EXACT after verified ov009 leaves02155C24/02155C6C attest +170/+178. TU suggest-split diagnostic completed before leaf shards: MATCH, no viable cut. Prior once300 consumed, never repeated.
 * Fresh retry: 10 one runs plus TU; assignment-return85, constant local return10, raw name/pair/union and flag widths10; initializer closes concrete bytes. No volatile or input-domain restriction.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A8264_obj 0x021A8264  data  ov009  a4
 *   d_021A1C6C     0x021A1C6C  data  ov009  a1
 *   func_0203D798  0x0203D798  arm
 *   func_0205C6AC  0x0205C6AC  arm
 *   func_0205C758  0x0205C758  arm
 *   func_0205C88C  0x0205C88C  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0205C8E0  0x0205C8E0  arm
 *   func_0216AB20  0x0216AB20  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0216B0E0  0x0216B0E0  arm
 *   func_0216AE88  0x0216AE88  arm
 *   func_0216B1E0  0x0216B1E0  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02168994  0x02168994  arm
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02155F58  0x02155F58  thumb  ov009
 *   func_02155B98  0x02155B98  thumb  ov009
 *   func_02155C0C  0x02155C0C  thumb  ov009
 *   func_02155C24  0x02155C24  thumb  ov009
 *   func_02155C28  0x02155C28  thumb  ov009
 *   func_02155C6C  0x02155C6C  thumb  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x100];
    void *w100;
    char pad104[0x108 - 0x104];
    void *w108;
    char x10C[0x754 - 0x10C];
    int state;
    int w758;
    char pad75C[0x76C - 0x75C];
    int w76C;
    char pad770[0x7A9 - 0x770];
    u8 b7A9;
} G;

typedef struct {
    u16 a;
    u16 b;
    char buf[0x54];
} Req;

typedef void (*Fn)(void);
typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

extern G *d_021A8264;
extern char d_021A8264_obj[];
extern char d_021A1C6C[];
void *func_0203D798(void);
void func_0205C6AC(void *p, u16 a, u16 b, u16 c);
void func_0205C758(void);
int func_0205C88C(void);
int func_0205CA20(void);
void func_0205C8E0(void);
void func_0216AB20(void *a, int b, char *c, int d, int e, void *f, int g);
void func_02087C88(OSOwnerInfo *p);
int func_0216B0E0(u16 *r, int a, Fn cb, void *b);
void func_0216AE88(void);
int func_0216B1E0(int a, Fn b, void *c, Fn d, void *e, Fn f, void *g);
void func_0203C9AC(int a, unsigned int b, unsigned int c, unsigned int d);
void func_02168994(Fn f, int a);
void func_02155374(int v);
int func_02155F58(void);
void func_02155B98(void);
void func_02155C0C(void);
void func_02155C24(void);
void func_02155C28(void);
void func_02155C6C(void);

int func_021554C8(void)
{
    OSOwnerInfo info;
    void *m;
    int flag;
    int ret;

    switch (d_021A8264->state) {
    case 0:
        func_0203D798();
        func_0205C6AC(d_021A8264->x10C, 2, 1, 0x14);
        func_0205C758();
        func_02155374(1);
        d_021A8264->w76C = 0;
    case 1:
        if (func_0205C88C() != 0) {
            if (func_0205CA20() == 4)
                func_02155374(2);
            else
                func_02155374(14);
        } else {
            func_0205C8E0();
            break;
        }
    case 2:
        ret = func_02155F58();
        if (ret != 0)
            return ret;
        flag = 0;
        m = d_021A8264->w100;
        if (m != 0)
            flag = 0x20;
        func_0216AB20(d_021A8264->w108, 0x2FC6, d_021A1C6C, 0, 0, m, flag);
        d_021A8264->b7A9 = 1;
        { u16 name[2] = {0, 0};
        func_02087C88(&info);
        func_0216B0E0(name, 0, func_02155B98, 0);
        }
        func_02155374(3);
    case 3:
        func_0216AE88();
        break;
    case 4:
        if (d_021A8264->w100 != 0) {
            if (func_0216B1E0(0, func_02155C0C, d_021A8264->w108,
                              func_02155C24, d_021A8264_obj, func_02155C28,
                              d_021A8264_obj) == 0) {
                func_0203C9AC(0, 0, 0, 0x3EE);
            } else {
                func_02168994(func_02155C6C, 0);
                func_0216AE88();
            }
        }
        func_02155374(5);
        break;
    case 5:
        func_0216AE88();
        if (d_021A8264->w100 == 0)
            func_02155374(6);
        break;
    case 6:
        func_0216AE88();
        { int code = 0x3EF; d_021A8264->w758 = code; return code; }
    }
    return func_02155F58();
}
