/*
 * function: func_021D7040
 * address:  0x021D7040
 * packet:   pkt_ov093_021D7040
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021F3CB0     0x021F3CB0  data
 *   func_021D6F08  0x021D6F08  thumb  ov093
 *   func_021D7494  0x021D7494  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    u32 lo : 24;
    u32 b24 : 1;
    u32 b25 : 1;
    u32 b26 : 1;
    u32 b27 : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 top : 2;
} Flags;

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    u8 pad8[0x10];
    Flags f18;
} Node;

typedef struct {
    u32 f0;
    Node *head;
} List;

extern List g_021F3CB0;
extern void func_021D6F08(void);
extern void func_021D7494(Node *n);

void func_021D7040(Node *n)
{
    if (n != 0) {
        if (n->f18.b29) {
            if (n->f18.b24) {
                n->f18.b27 = 1;
                return;
            }
            if (n == g_021F3CB0.head)
                g_021F3CB0.head = n->next;
            if (n->prev != 0)
                n->prev->next = n->next;
            if (n->next != 0)
                n->next->prev = n->prev;
            func_021D6F08();
            func_021D7494(n);
        }
    }
}
