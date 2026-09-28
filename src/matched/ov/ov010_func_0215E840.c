/*
 * function: func_0215E840
 * address:  0x0215E840
 * packet:   pkt_ov010_0215E840
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fill the 0x14-byte Info for the field: id, the ov021 handles, and the
 * flags word from the object kind, the map tests and the save flags.
 * One lever: the u16 for func_021CD440 is declared before x (stack order).
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3250  0x021A3250  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021A3128  0x021A3128  thumb  ov021
 *   func_021A3504  0x021A3504  thumb  ov021
 *   func_021A3524  0x021A3524  thumb  ov021
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0215F118  0x0215F118  thumb  ov010
 *   func_02013C40  0x02013C40  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_0201400C  0x0201400C  thumb
 *   func_02014018  0x02014018  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_02012B70  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

typedef struct Info {
    u16 id;             /* 0x00 */
    u16 flags;          /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    void *obj;          /* 0x0C */
    void *field;        /* 0x10 */
} Info;

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u16 func_02188C9C(void *field);
extern u32 func_02188C80(void *field);
extern void *func_02188CB4(void *field);
extern void *func_02188C7C(void *field);
extern u32 func_021A3098(void *q);
extern void *func_021A3250(void *q);
extern u32 func_021A3050(void *q);
extern u32 func_021A30C8(void *q);
extern u32 func_021A3128(void *q, u32 a);
extern int func_021A3504(void *q, u32 b, u32 c);
extern int func_021A3524(void *q, u32 b, u32 c);
extern void func_021A35FC(void *q, u16 *x, u16 *y, u16 *z);
extern u16 func_0216D598(void *obj);
extern void func_0216D88C(void *obj, VecFx32 *out);
extern int func_0216E5FC(u16 kind);
extern int func_0216E5B0(void *map, const VecFx32 *pos);
extern int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
extern int func_02013C40(u16 id);
extern int func_02013C50(u16 id);
extern void *func_020120F4(u32 v);
extern void *func_02012B38(void *p);
extern u32 func_02014470(void *p);
extern int func_021CD440(void *field, u16 *out);
extern int func_02013FFC(u16 id);
extern int func_0201400C(u16 id);
extern int func_02014018(u16 id);
extern int func_02013E04(u16 id);
extern int func_02012B70(void *p);

extern const Area d_021711EC;
extern const Area d_021711F4;

void func_0215E840(void *field, Info *out)
{
    VecFx32 pos;
    u16 v;
    u16 x;
    u16 y;
    u16 z;
    void *q;
    void *obj;
    void *map;
    u16 kind;
    u32 a;
    u32 b;
    u32 c;

    MI_CpuFill8(out, 0, sizeof(Info));
    out->id = func_02188C9C(field);
    out->f08 = func_02188C80(field);
    out->field = field;
    q = func_02188CB4(field);
    out->f04 = func_021A3098(q);
    obj = func_021A3250(q);
    out->obj = obj;
    if (obj != 0) {
        kind = func_0216D598(obj);
        map = func_02188C7C(field);
        func_0216D88C(obj, &pos);
        if (func_0216E5FC(kind) && func_0216E5B0(map, &pos) == 0)
            out->flags |= 8;
        if (kind == 0x6C)
            out->flags |= 1;
    }
    a = func_021A3050(q);
    b = func_021A30C8(q);
    c = func_021A3128(q, a);
    if (func_021A3504(q, b, c) == 1)
        out->flags |= 2;
    if (func_021A3524(q, b, c) == 1)
        out->flags |= 4;
    if (func_02013C40(out->id) == 1) {
        out->flags |= 0x10;
        out->flags |= 0x40;
    }
    if (func_02013C50(out->id) == 1)
        out->flags |= 0x80;
    if (func_02014470(func_02012B38(func_020120F4(out->f08))) & 1)
        out->flags |= 0x20;
    if (func_021CD440(field, &v) == 1)
        out->flags |= 0x400;
    if (func_02013FFC(out->id)) {
        func_021A35FC(func_02188CB4(out->field), &x, &y, &z);
        if (func_0201400C(out->id) && func_0215F118(&d_021711EC, x, z, 0x113, field))
            out->flags |= 0x20;
        if (func_02014018(out->id) && func_0215F118(&d_021711F4, x, z, 0x112, field))
            out->flags |= 8;
    }
    if (func_02013E04(out->id) == 0) {
        out->flags = 0;
    } else {
        out->flags |= 0x100;
        out->flags |= 0x200;
    }
    if (func_02012B70(func_020120F4(out->f08)) == 1)
        out->flags = 0;
}
