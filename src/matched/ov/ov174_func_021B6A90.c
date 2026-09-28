/*
 * function: func_021B6A90
 * address:  0x021B6A90
 * packet:   pkt_ov174_021B6A90
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021B7398  0x021B7398  data  a4
 */
typedef struct Obj Obj;
struct Obj {
    unsigned char pad00[0x0C];
    unsigned char state;
    unsigned char pad0D[0x34 - 0x0D];
    int pending;
    unsigned char pad38[0x40 - 0x38];
    unsigned char *steps;
    unsigned char pad44[0x89 - 0x44];
    unsigned char stepIdx;
};

typedef struct Ent {
    void (*init)(Obj *);
    int (*update)(Obj *);
} Ent;

extern const Ent g_021B7398[];

void func_021B6A90(Obj *o)
{
    unsigned int cur = o->steps[o->stepIdx * 4];

    if (o->pending == 1) {
        o->pending = 0;
        g_021B7398[cur].init(o);
    }
    if (g_021B7398[cur].update(o) == 1) {
        unsigned int next;
        o->stepIdx++;
        next = o->steps[o->stepIdx * 4];
        if (next != 0) {
            g_021B7398[next].init(o);
            return;
        }
        o->state = 2;
    }
}
