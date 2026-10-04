/*
 * function: func_021F3B64
 * address:  0x021F3B64
 * packet:   pkt_ov048_021F3B64
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012F68  0x02012F68  thumb
 *   func_0200EC14  0x0200EC14  thumb
 *   func_0200EC2C  0x0200EC2C  thumb
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

extern void *func_02012F68(void **h);
struct U16Vec;
extern int func_0200EC14(char *p);
struct Src0200EC2C;
struct Dst0200EC2C;
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);

void func_021F3B64(u16 *p, u32 *out, int *cnt)
{
    void *s;
    int i;
    St st;

    s = func_02012F68((void **)(((int *)p)[2]));
    *cnt = func_0200EC14(s);
    for (i = 0; i < *cnt; i++) {
        st.p0 = func_020457B0(0x40, p[0]);
        st.p1 = func_020457B0(0x40, p[0]);
        func_0200EC2C(s, i, (struct Dst0200EC2C *)&st);
        out[i] = st.c;
        func_02045808(st.p0);
        func_02045808(st.p1);
    }
}
