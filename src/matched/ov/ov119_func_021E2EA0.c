/*
 * function: func_021E2EA0
 * address: 0x021E2EA0
 * packet: pkt_ov119_021E2EA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 * symbols:
 *   func_02011558 0x02011558 thumb
 */
struct IcaAnime;
extern void func_02011558(struct IcaAnime *p);
void func_021E2EA0(char *p) {
    if (*(void **)(p+0x90)) {func_02011558(*(void **)(p+0x90)); *(void **)(p+0x90)=0;}
    if (*(void **)(p+0x94)) {func_02011558(*(void **)(p+0x94)); *(void **)(p+0x94)=0;}
    if (*(void **)(p+0x98)) {func_02011558(*(void **)(p+0x98)); *(void **)(p+0x98)=0;}
    if (*(void **)(p+0x9c)) {func_02011558(*(void **)(p+0x9c)); *(void **)(p+0x9c)=0;}
}
