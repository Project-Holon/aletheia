/*
 * function: func_0220B9E0
 * address:  0x0220B9E0
 * packet:   pkt_0220B9E0
 * region:   ov207
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_0220270C  0x0220270C  thumb
 *   func_02202DC4  0x02202DC4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02202228  0x02202228  thumb
 *   d_0220BBEC     0x0220BBEC  data  ov207
 *   d_0220BBF8     0x0220BBF8  data  ov207
 */
#include "../include/Obj00181.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int v0;
    int v1;
    int v2;
} S3;

extern u8 func_020355C4(void);
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_0220270C(int *p, int n, S3 *s);
extern int  func_02202DC4(int *p, void *a, void *b);
extern void func_020355D8(int a);
extern void func_02202228(int *p);

extern char d_0220BBEC[];
extern char d_0220BBF8[];

void func_0220B9E0(int *a)
{
    S3 s;

    switch (a[19]) {
    case 0:
    case 3:
        break;
    case 1:
        ((u8 *)a)[0x50] = (func_020355C4() == 0) ? 1 : 0;
        {
            int r5 = (int)func_02045B38(0, 2, 0xe9, ((struct Obj00181 *)a)->f0);
            s.v0 = (int)func_02045EC0((struct MsgBank *)r5, 0);
            s.v1 = (int)func_02045EC0((struct MsgBank *)r5, 1);
            s.v2 = 1;
            func_0220270C((int *)a[21], 4, &s);
            STRBUF_Delete((struct U16Vec *)s.v0);
            STRBUF_Delete((struct U16Vec *)s.v1);
            MSGDATA_Delete((struct Rec *)r5);
            a[19] = 2;
        }
        break;
    case 2:
        {
            int r5 = func_02202DC4((int *)a[21], d_0220BBEC, d_0220BBF8);
            if (r5 == -1)
                break;
            func_0220270C((int *)a[21], 0, 0);
            a[19] = 3;
            if (r5 == 0)
                a[16] = 1;
            else
                a[16] = 0;
            func_020355D8(((u8 *)a)[0x50] ? 0 : 1);
        }
        break;
    }
    func_02202228((int *)a[21]);
}
