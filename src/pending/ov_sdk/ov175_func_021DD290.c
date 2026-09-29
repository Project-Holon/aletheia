/*
 * function: func_021DD290
 * address:  0x021DD290
 * packet:   pkt_ov175_021DD290
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (41 bytes differ: 25-byte ticket byte-pair copy loads [0] then [1] with a separate add; original loads [1] then [0] with fused post-increment ldrb r3,[r2],#2)
 *
 * sdk:      sakeSetProfile (sakemain.o)
 *
 * symbols:
 *   (none)
 */

typedef struct {
    char b[25];
} SAKELoginTicket;

typedef struct SAKEInternal {
    unsigned char pad0[0x24];
    int profileSet;
    int profileId;
    SAKELoginTicket loginTicket;
} SAKEInternal;

void func_021DD290(SAKEInternal *sake, int profileId, char *loginTicket)
{
    SAKELoginTicket *src = (SAKELoginTicket *)loginTicket;

    sake->profileId = profileId;
    sake->loginTicket = *src;
    sake->profileSet = 1;
}
