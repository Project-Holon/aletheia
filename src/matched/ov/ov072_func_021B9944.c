/*
 * function: func_021B9944
 * address: 0x021B9944
 * packet: pkt_ov072_021B9944
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef struct Callback Callback;
struct Callback { void (*call)(Callback *, int *, int); int state, value, arg; };
void func_021B9944(Callback *p) {
    if (p->state == 0) p->call(p, &p->value, p->arg);
}
