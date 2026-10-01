/*
 * function: func_021DF144
 * address: 0x021DF144
 * packet: pkt_ov170_021DF144
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 */
typedef struct {
    char pad[18];
    unsigned char level:7;
    unsigned char egg:1;
    unsigned char gender:4;
    unsigned char showgender:1;
    unsigned char shiny:1;
    unsigned char mark:2;
} Summary;
extern void func_021EC000(char *w, int i, int v);
void func_021DF144(char *w, Summary *s)
{
    if (s->shiny == 0 || s->egg == 1)
        func_021EC000(w, 25, 0);
    else
        func_021EC000(w, 25, 1);
    if (s->mark == 0) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 0);
    } else if (s->mark == 1) {
        func_021EC000(w, 26, 0);
        func_021EC000(w, 27, 1);
    } else {
        func_021EC000(w, 26, 1);
        func_021EC000(w, 27, 0);
    }
}
