/*
 * function: func_0272F740
 * address:  0x0272F740
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02150FEC 0x02150FEC data
 *   func_02087B04 0x02087B04 arm
 *   func_0272F570 0x0272F570 arm twl
 *   func_0272F368 0x0272F368 arm twl
 */
typedef unsigned int u32;
typedef unsigned char u8;

struct Node {
    struct Node *next;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct Obj {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    char pad0b[0xc];
    u32 f20;
    u32 f24;
    char pad1[8];
    u32 f30;
    int (*f34)(u32, u32, u32, u32);
    int (*f38)(u32, u32, u32, u32);
    u32 id;
    struct Node *cur;
    struct Node *free_a;
    struct Node *used_a;
    struct Node *cache_a;
    struct Node *free_b;
    struct Node *used_b;
    struct Node *cache_b;
};

struct IdSrc {
    u32 f0;
    u32 id;
};
extern struct IdSrc data_02150FEC;
extern int func_02087B04(void);
extern void func_0272F570(struct Obj *obj, u8 *buf, u32 off, u32 len);
extern void func_0272F368(struct Obj *obj, u8 *buf, u32 off, u32 len);

void func_0272F740(struct Obj *obj, u8 *buf, u32 off, u32 len)
{
    u32 mask;
    u32 head;
    u32 bulk;

    obj->id = data_02150FEC.id;
    obj->cur = 0;
    if (len >= obj->f20 << 4 && func_02087B04() != 1) {
        mask = obj->f20 - 1;
        head = mask & (obj->f20 - off);
        bulk = ~mask & (len - head);
        if (head != 0) {
            func_0272F570(obj, buf, off, head);
            off += head;
            len -= head;
            buf += head;
        }
        if (bulk != 0) {
            func_0272F368(obj, buf, off, bulk);
            off += bulk;
            len -= bulk;
            buf += bulk;
        }
    }
    func_0272F570(obj, buf, off, len);
}
