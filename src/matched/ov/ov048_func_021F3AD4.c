/*
 * function: func_021F3AD4
 * address:  0x021F3AD4
 * packet:   pkt_ov048_021F3AD4
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_0200ECD0  0x0200ECD0  thumb
 *   func_0200ECF0  0x0200ECF0  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct St {
    void *p0;
    void *p1;
    int a;
    int b;
    u16 c;
    u8 pad[10];
} St;

struct Big;
extern void *func_02012EBC(struct Big *p);
extern u32 SAVE_CONTROL_LoadExtraSave(void *s, u32 id, u32 heap);
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct U16Vec;
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern int func_0200ECD0(char *o, int idx);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);

void func_021F3AD4(const u16 *p, u32 *out, int *cnt)
{
    int i;
    void *s;
    void *t;
    St st;

    i = 0;
    *cnt = 0;
    s = func_02012EBC((struct Big *)(((int *)p)[2]));
    if (SAVE_CONTROL_LoadExtraSave(s, 8, p[0]) - 1 <= 1) {
        t = func_020073D8(s, 8, i);
        if (func_0200ECB4(t) != 0) {
            *cnt = func_0200ECD0(t, i);
            for (; i < *cnt; i++) {
                st.p0 = func_020457B0(0x40, p[0]);
                st.p1 = func_020457B0(0x40, p[0]);
                func_0200ECF0(t, 0, (void *)i, &st);
                out[i] = st.c;
                func_02045808(st.p0);
                func_02045808(st.p1);
            }
        }
    }
    func_020072A4(s, 8);
}
