/*
 * function: func_021BF030
 * address: 0x021BF030
 * packet: pkt_ov204_021BF030
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF080 0x021BF080 thumb ov204
 *   d_021C09D8 0x021C09D8 data a4
 */
typedef struct Command { unsigned tag; unsigned data[5]; } Command;
typedef struct Slot { unsigned data[3]; } Slot;
typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;
extern int (*const d_021C09D8[])(void *, Slot *, void *);
extern void func_021BF080(char *, unsigned char);
int func_021BF030(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!d_021C09D8[q->tag](p, &p->slots[i], q->data)) result = 1;
            else func_021BF080((char *)p, i);
        }
    }
    return result;
}
