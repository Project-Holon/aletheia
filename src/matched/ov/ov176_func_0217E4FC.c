/*
 * function: func_0217E4FC
 * address:  0x0217E4FC
 * packet:   pkt_ov176_0217E4FC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle   0x020399A8  arm
 *   GFL_NET_GetHandleNetID   0x0203D1A4  arm
 *   func_02034714   0x02034714  arm
 *   d_0217E64C      0x0217E64C  data  ov176
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_0217E64C[];

int func_0217E4FC(int a, int b)
{
    if (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        func_02034714(d_0217E64C, 0, d_0217E64C);
        return 0;
    }
    return b + 6;
}
