/*
 * function: func_02185F6C
 * address:  0x02185F6C
 * packet:   pkt_ov020_02185F6C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec;
void func_02045A38(struct U16Vec *a, unsigned short *b, unsigned int c);
void *func_02008F08(int a0);
void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
void func_02008FA0(struct Sub02008F80Obj *obj, u8 value);
void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
void func_02008FB4(struct Sub02008F80Obj *obj, u8 value);
void func_02008FBC(struct Sub02008F80Obj *obj, u8 value);
void func_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
void func_02008FC4(struct Sub02008F80Obj *obj, u16 value);
struct Sub02008F80Obj *func_02008FEC(void *sys);
void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
u32 func_020307B0(void *p);
void func_02045808(struct U16Vec *vec);
void func_02045C04(struct Rec *rec);
extern char d_02187DA4[];
extern char d_02187DAC[];
extern char d_02187DB4[];

void func_02185F6C(int a)
{
    int r6 = (int)func_02045B38(0, 2, 0xbe, 1);
    int r7 = (int)func_02045EC0((struct MsgBank *)r6, 0x3b);
    int r4;
    char buf[0x20];

    func_02045A38((struct U16Vec *)r7, (unsigned short *)buf, 0x10);
    r4 = (int)func_02008F08(1);
    func_02008F88((struct Sub02008F80Obj *)r4, buf);
    func_02008FA0((struct Sub02008F80Obj *)r4, 1);
    func_02008FA8((struct Sub02008F80Obj *)r4, 3);
    func_02008FB4((struct Sub02008F80Obj *)r4, 2);
    func_02008FBC((struct Sub02008F80Obj *)r4, 0x15);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DA4, 0);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DAC, 1);
    func_02008FD8((struct Sub02008F80Obj *)r4, d_02187DB4, 2);
    func_02008FC4((struct Sub02008F80Obj *)r4, 0x58F);
    func_0200903C(func_02008FEC((void *)a), 0, 0, (const struct Sub02008F80Obj *)r4);
    func_020307B0((void *)r4);
    func_02045808((struct U16Vec *)r7);
    func_02045C04((struct Rec *)r6);
}
