/*
 * function: func_021FC744
 * address: 0x021FC744
 * packet: pkt_ov094_021FC744
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: arm9 func_02051614 filed as src/matched/arm9/func_02051614.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 * symbols:
 *   func_021F8684 0x021F8684 thumb ov094
 *   func_021F722C 0x021F722C thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FF16C 0x021FF16C thumb ov094
 *   func_021FFCB0 0x021FFCB0 thumb ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_02200494 0x02200494 thumb ov094
 *   func_021F8700 0x021F8700 thumb ov094
 *   func_0220985C 0x0220985C thumb ov094
 *   func_02051614 0x02051614 arm
 *   func_021F8324 0x021F8324 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02006BD0 0x02006BD0 thumb
 */
typedef enum { SLOT_ZERO, SLOT_LAST = 14 } Slot;
typedef union {
    unsigned word;
    struct {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned gap4 : 3;
        unsigned b7 : 1;
        unsigned b8 : 1;
        unsigned gap9 : 2;
        unsigned b11 : 1;
        unsigned gap12 : 4;
        unsigned b16 : 1;
    } bit;
} Flags;
typedef struct {
    Flags flags;
    char pad[8];
    void *objects[16];
    char pad2[0x240 - 0x4c];
    unsigned mode;
    int f244;
    char pad3[0x26c - 0x248];
    int slots[6];
} State;
extern int func_021F8684(void);
extern int func_021F722C(char *p);
extern int func_021F8694(void);
extern void func_021FF16C(void *);
extern int func_021FFCB0(void *, int);
typedef unsigned int   u32;
extern int func_021FFD9C(char *p, int key);
extern int func_02200494(char *p, int key);
extern int func_021F8700(void);
extern int func_0220985C(void *);
extern int func_02051614(int **p);
extern int func_021F8324(unsigned);
extern int func_02006238(void);
extern int func_02006224(unsigned);
extern u32 func_02006BD0(u32 i);

int func_021FC744(int a, State *s)
{
    int i;
    Slot j;

    if (s->mode <= 1) {
        if (func_021F722C((char *)func_021F8684()) == 1) return 0;
        if (s->flags.bit.b1) {
            s->flags.bit.b1 = 0;
            s->f244 = 1;
            func_021FF16C((void *)func_021F8694());
        }
    }
    if (s->mode == 0 || s->mode == 3) {
        for (j = 0; j < 14; j++) {
            if (func_021FFCB0((void *)func_021F8694(), j) == 1) return 0;
        }
    }
    if (s->mode == 4) {
        for (j = 8; j < 14; j++) {
            if (func_021FFD9C((char *)func_021F8694(), j)) {
                if (func_02200494((char *)func_021F8694(), j) == 1) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 5) {
        if (func_0220985C((void *)func_021F8700()) == 1) return 0;
    }
    if (s->mode == 0 || s->mode == 2) {
        for (i = 0; i < 16; i++) {
            if (s->objects[i] != 0) {
                if (func_02051614(s->objects[i]) != 0) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 6 || s->mode == 8) {
        if (func_021F8324(0) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 7 || s->mode == 8) {
        if (func_021F8324(1) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 9) {
        if (func_021F8324(3) != 0) return 0;
    }
    if (s->mode == 10) {
        if (func_02006238() != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 11) {
        if (func_02006224(1) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 12) {
        if (func_02006224(2) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 13) {
        if (func_02006224(4) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 14) {
        if (func_02006224(3) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 15) {
        if (func_02006224(0) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 16) {
        if (s->flags.bit.b11) return 0;
        for (i = 0; i < 6; i++) {
            if (s->slots[i] != -1) {
                if (func_02006BD0(s->slots[i]) != 0) return 0;
                s->slots[i] = -1;
            }
        }
    }
    if (s->mode == 0 || s->mode == 17) {
        if (s->flags.bit.b8) return 0;
    }
    return 1;
}
