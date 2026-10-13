/*
 * function: UNION_APP_Create
 * address:  0x02183B60
 * packet:   pkt_ov022_02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   UNION_APP_SetMemberEntry  0x02183FB8  thumb  ov022
 *   UNION_APP_Close  0x02184114  thumb  ov022
 *   UNION_APP_SetReady  0x0218416C  thumb  ov022
 *   sUnionAppFile     0x021841C0  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Rec20 {
    u32 w[8];
} Rec20;

extern u8 sUnionAppFile[];

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern u32 GFL_NET_IsParentAid(void);
extern void MI_CpuFill8(void *p, int v, int n);
extern void func_02087C6C(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void UNION_APP_SetMemberEntry(u8 *s, u8 *a, int idx, u8 *src);
extern int UNION_APP_Close(u8 *s);
extern void UNION_APP_SetReady(char *p);

u8 *UNION_APP_Create(u8 *a, int heap, int kind, Rec20 *src)
{
    u8 *s;
    u8 buf[0x28];

    s = func_02030734(heap, 0x100, 1, (const char *)sUnionAppFile, 0x4d);
    if (GFL_NET_IsParentAid() == 1) {
        s[1] = 3;
    }
    s[0] = kind;
    s[0x10] = 0xff;
    s[0x11] = 0xff;
    MI_CpuFill8(buf, 0, 0x28);
    *(Rec20 *)buf = *src;
    func_02087C6C(buf + 0x20);
    UNION_APP_SetMemberEntry(s, a, GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())), buf);
    UNION_APP_Close(s);
    UNION_APP_SetReady((char *)s);
    return s;
}
