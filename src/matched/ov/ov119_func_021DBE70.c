/*
 * function: func_021DBE70
 * address:  0x021DBE70
 * packet:   pkt_ov119_021DBE70
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The bound block after func_021E4DBC closes only with its six locals
 * declared without initialisers and assigned afterwards; about a fifth of
 * the declaration orders then match (docs/notes/pkt_ov119_021DBE70.c.txt).
 *
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_020355D8 0x020355D8 arm
 *   func_0203630C 0x0203630C arm
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021E4E0C 0x021E4E0C thumb
 *   func_021DB4EC 0x021DB4EC thumb
 *   func_021E4DBC 0x021E4DBC thumb
 *   func_021DB4B4 0x021DB4B4 thumb
 *   func_021DB7AC 0x021DB7AC thumb
 *   func_021D8B38 0x021D8B38 thumb
 *   func_021D8C84 0x021D8C84 thumb
 *   func_021D8B54 0x021D8B54 thumb
 *   func_021D8C0C 0x021D8C0C thumb
 *   func_021DB52C 0x021DB52C thumb
 *   func_021DF7F0 0x021DF7F0 thumb
 *   func_021D8AF4 0x021D8AF4 thumb
 *   func_021D8B0C 0x021D8B0C thumb
 *   func_021D8DD0 0x021D8DD0 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_021DD0CC 0x021DD0CC thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E0FF4 0x021E0FF4 thumb
 *   func_021D8E84 0x021D8E84 thumb
 *   func_021DA064 0x021DA064 thumb
 *   func_021D8AA8 0x021D8AA8 thumb
 *   func_021DD34C 0x021DD34C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021DF708 0x021DF708 thumb
 *   func_021E4A1C 0x021E4A1C thumb
 *   func_021DBDB4 0x021DBDB4 thumb
 *   func_021D9F24 0x021D9F24 thumb
 *   func_021D9548 0x021D9548 thumb
 *   func_021D8C6C 0x021D8C6C thumb
 *   func_021DA0CC 0x021DA0CC thumb
 *   func_021E6544 0x021E6544 thumb
 *   func_021DBD3C 0x021DBD3C thumb
 *   func_0204B92C 0x0204B92C arm
 *   func_021DB89C 0x021DB89C thumb
 *   func_021DC2B0 0x021DC2B0 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 */

typedef unsigned int u32;

extern int TOUCHPANEL_GetCont(void);
typedef unsigned char  u8;
struct MsgBank;
struct S;
extern void func_020355D8(u8 v);
extern unsigned int func_0203630C(void);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern int func_021E4E0C(char *p, int *out);
extern int func_021DB4EC(char *p, int v);
extern int func_021E4DBC(char *p);
extern int func_021DB4B4(int v);
extern void func_021DB7AC(char *p, int v, int w);
extern void func_021D8B38(char *p);
extern void func_021D8C84(void *p);
extern void func_021D8B54(void *p);
extern void func_021D8C0C(void *p);
extern void func_021DB52C(char *p);
extern void func_021DF7F0(void *p);
extern int func_021D8AF4(int v, char *p);
extern int func_021D8B0C(int a, int b);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021DD0CC(char *p, int e);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E0FF4(void *p, int a, int flag);
extern void func_021D8E84(void *p, int next);
extern void func_021DA064(char *p);
extern int func_021D8AA8(void *p);
extern int func_021DD34C(char *p, int a, int b);
extern void func_020061E4(u32 a);
extern void func_021DF708(void *p);
extern void func_021E4A1C(char *p);
extern int func_021DBDB4(char *p);
extern int func_021D9F24(char *p, int v);
extern int func_021D9548(char *p, int a, int b);
extern void func_021D8C6C(void *p);
extern void func_021DA0CC(char *p);
extern void func_021E6544(char *p);
extern void func_021DBD3C(char *p);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_021DB89C(char *p);
extern void func_021DC2B0(char *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *p);

#define I(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(short *)((p) + (o)))

static inline int poll_a(void)
{
    int r = func_020362DC();
    if (r)
        func_020355D8(0);
    return r;
}

static inline int poll_b(void)
{
    int r = TOUCHPANEL_GetTrg();
    if (r)
        func_020355D8(1);
    return r;
}

void func_021DBE70(char *p)
{
    int n;
    int e;
    p[0x11EA] = 1;
    if (TOUCHPANEL_GetCont()) {
        func_020355D8(1);
        if (func_0203630C())
            return;
    }
    if (func_020355C4() && poll_a()) {
        func_020355D8(0);
        if (func_021E4E0C(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2 && I(p, 0xF78) >= 3)
                I(p, 0xF78) = 2;
        } else if (func_021DB4EC(p, I(p, 0xF74)) == 0) {
            int end;
            int a;
            int t;
            int cur;
            int b;
            int lim;
            t = func_021E4DBC(p);
            cur = I(p, 0xF74);
            a = t + 5;
            b = t + 10;
            lim = I(p, 0x634);
            end = cur;
            if (b >= lim && cur < 0x14)
                end = cur + (lim + 1);
            if (a < end)
                H(p, 0x107C) = func_021DB4B4(cur + 1) - 0x100;
            else
                H(p, 0x107C) = func_021DB4B4(cur);
            H(p, 0x1080) = -1;
            I(p, 0x1084) = 1;
            func_021DB7AC(p, 0, 1);
            H(p, 0x107A) = 0;
            return;
        }
        func_021D8B38(p);
        H(p, 0x107A) = 0;
        return;
    }
    if (poll_a() || poll_b())
        H(p, 0x107A) = 0;
    if (poll_b()) {
        func_021D8C84(p);
        I(p, 0xF98) = -1;
        I(p, 0xF94) = -1;
    }
    func_021D8B54(p);
    func_021D8C0C(p);
    func_021DB52C(p);
    func_021DF7F0(p);
    if (poll_a() == 1) {
        func_020355D8(0);
        if (func_021E4E0C(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2) {
                if (I(p, 0xF78) >= 3)
                    I(p, 0xF78) = 0;
            } else if (I(p, 0xF78) >= 5)
                I(p, 0xF78) = 0;
        }
        e = (int)func_021D8DD0((void *)I(p, 0x828), func_021D8AF4(I(p, 0xF74), p), func_021D8B0C(I(p, 0xF74), I(p, 0xF78)), p);
        if (e && func_02017E88((void *)e, 0xA9, 0)) {
            if (func_021DD0CC(p, e)) {
                MSGDATA_ReadString((struct MsgBank *)I(p, 0x720), 0x8E, (void *)I(p, 0x738));
                func_021E0FF4(p, 1, 0);
                func_021D8E84(p, (int)func_021DA064);
                return;
            }
            I(p, 0xF98) = func_021D8AF4(I(p, 0xF74), p);
            I(p, 0xF94) = func_021D8B0C(I(p, 0xF74), I(p, 0xF78));
            func_020355D8(0);
            if (func_021D8AA8(p) && func_021DD34C(p, I(p, 0xF98), I(p, 0xF94)) != -1) {
                func_020061E4(0x626);
                func_021D8E84(p, (int)func_021DF708);
                return;
            }
            func_021D8DD0((void *)I(p, 0x828), I(p, 0xF98), I(p, 0xF94), p);
            func_021D8C84(p);
            func_021E4A1C(p);
            func_021DBDB4(p);
            return;
        }
    }
    switch (func_021D9F24(p, 0)) {
    case 3:
        return;
    case 2:
        break;
    case 1:
        func_020355D8(1);
        I(p, 0xF70) = 1;
    default:
        if (!TOUCHPANEL_GetCont()) {
            if (I(p, 0x1088) && I(p, 0xF5C) && I(p, 0xF60)) {
                I(p, 0x1088) = 0;
                I(p, 0xF5C) = 0;
                if (func_021D9548(p, I(p, 0xF80), I(p, 0xF7C))) {
                    I(p, 0xF80) = -1;
                    I(p, 0xF7C) = -1;
                    func_021D8C6C(p);
                    func_021D8E84(p, (int)func_021DA0CC);
                    return;
                }
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                I(p, 0xF84) = I(p, 0xF7C);
                I(p, 0xF88) = I(p, 0xF80);
                I(p, 0xF60) = 0;
                func_021B6558((unsigned char *)I(p, 0x9C0), 8, 1);
                TOUCHBAR_SetButtonEnabled((unsigned char *)I(p, 0x9C0), 8, 1);
                func_021E6544(p);
                func_020061E4(0x72A);
                func_021D8E84(p, (int)func_021DBD3C);
                return;
            }
            if (I(p, 0x1088) && I(p, 0xF60) && I(p, 0xF70)) {
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                func_021DBDB4(p);
                return;
            }
            if (I(p, 0xF7C) != -1 && I(p, 0xF80) != -1) {
                func_021D8C84(p);
                func_021D8B38(p);
            } else {
                func_021D8C84(p);
            }
            I(p, 0x1088) = 0;
            I(p, 0xF5C) = 0;
            func_0204B92C((struct Obj *)I(p, 0xF04), 0);
        }
        func_021DB89C(p);
        if (TOUCHPANEL_GetCont())
            I(p, 0x1088) = 1;
        TOUCHBAR_Update((struct S *)I(p, 0x9C0));
        switch (TOUCHBAR_GetPressedButtonIdIfPressing((u8 *)I(p, 0x9C0))) {
        case 1:
        case 7:
        case 8:
            func_021D8E84(p, (int)func_021DC2B0);
            break;
        }
        break;
    }
}
