/*
 * function: func_021B8454
 * address: 0x021B8454
 * packet: pkt_ov172_021B8454
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane05: EXACT. w is a u32 local (callee keeps its real u16 return) declared
 *   between me and base: declaration order me, w, base, e gives slots 0x10, 0xC, 8, 4.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_LOWER_DATA_CreatePostWork 0x0203E808 arm
 *   GFL_NET_LOWER_DATA_DeletePostWork 0x0203E8C8 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE058 0x021BE058 thumb ov172
 *   func_021BE0A8 0x021BE0A8 thumb ov172
 *   func_021B7B20 0x021B7B20 thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021B8614 0x021B8614 thumb ov172
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern u32 GFL_NET_IsConnectMember(u32 index);
extern void GFL_NET_LOWER_DATA_CreatePostWork(u32 a, int b, u32 c, u32 d);
extern void GFL_NET_LOWER_DATA_DeletePostWork(int a);
extern u16 func_021BE00C(u16 *p);
extern u32 func_021BDFDC(void *p);
extern void func_021BE058(void *p, u32 v);
extern void func_021BE0A8(void *p, u32 v);
extern void func_021B7B20(int unused, char *base, int i);
extern void func_021B7740(void *p, char *q, int a, int b);
extern void func_021B8614(int unused, int unused2, void *p);

void func_021B8454(void *a, char *q)
{
    u32 count = 0;
    int flag = 0;
    u8 i;
    u32 me;
    u32 w;
    u32 base;
    char *e;

    me = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    w = func_021BE00C((u16 *)a);
    for (i = 0; i < 4; i++) {
        if (GFL_NET_IsConnectMember(i) == 1) {
            e = q + i * 64;
            if (*(u32 *)(e + 0x64) == 0) {
                base = func_021BDFDC(a);
                *(u32 *)(e + 0x64) = 1;
                if (i == me) {
                    *(u32 *)(e + 0x70) = 1;
                } else {
                    u8 j;
                    for (j = 0; j < 3; j++) {
                        u32 m = 1 << j;
                        if (!(m & *(u8 *)(q + 0x170))) {
                            GFL_NET_LOWER_DATA_CreatePostWork(0xC000, i, w, *(u32 *)(q + j * 4 + 0x164));
                            *(u8 *)(q + 0x170) |= (u8)m;
                            *(u8 *)(e + 0x78) = j;
                            break;
                        }
                    }
                    *(u8 *)(q + 0x182) |= (u8)(1 << i);
                    *(u32 *)(e + 0x7C) = 1;
                }
                func_021B7B20((int)a, (char *)base, i);
                flag = 1;
            }
            count = (u8)(count + 1);
        } else {
            u32 off = i << 6;
            char *e2 = q + off;
            if (*(u32 *)(e2 + 0x64) == 1) {
                *(u32 *)(e2 + 0x64) = 0;
                if (*(u32 *)(e2 + 0x70) == 0) {
                    GFL_NET_LOWER_DATA_DeletePostWork(i);
                    *(u8 *)(q + 0x170) -= (u8)(1 << *(u8 *)(e2 + 0x78));
                }
                if (*(u8 *)(q + 0x3AE) == i)
                    *(u32 *)(q + 0x194) = 0;
                flag = 1;
                *(u8 *)(q + 0x182) -= (u8)(flag << i);
                func_021B8614((int)a, (int)q, q + 0x64 + off);
            }
        }
    }
    if (flag == 1) {
        func_021BE058(a, count);
        func_021BE0A8(a, me);
    }
    func_021B7740(a, (char *)func_021BDFDC(a), 0, 1);
}
