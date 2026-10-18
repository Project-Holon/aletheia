/*
 * function: IRCi_Send
 * address:  0x0217A034
 * packet:   pkt_ov015_0217A034
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    w9_nm2: DIFF 10 B (was 16). A dedicated local buf = gIrcBuffer assigned after the copy loop (declared before pHeader) puts i in ip and the pointers in r6/r5; the final call keeps the pool word. Left: object stores sumLo before sumHi (scheduler swaps; tried order, masks, byte pointer, locals) and loop 2 counter is r1 not ip (tried i=0 hoists).
 * blocker:  10 concrete bytes, one allocator tie-break in the second loop.
 *           The image keeps the XOR counter i in r12/ip and therefore stores
 *           sumLo/sumHi in source order; mwcc here colours the fresh zero of
 *           the second loop r1 (freeing r1 first, so the two strb swap) and
 *           everything downstream moves. Verified unchanged by: plain/ternary
 *           loop spellings, while/do-while, a fresh loop variable, separate
 *           i/j, long/enum/register/unsigned i, i=0 hoisted before the stores,
 *           a named enum zero, explicit byte temporaries, p-reuse, and a
 *           2000-compile permuter anneal (plateau at 10). w8 also: a no-code
 *           `i = i;` self-assignment at the live-range boundary (idiom
 *           a-no-code-self-assignment-*), an enum-typed counter, and
 *           reusing `p` as the second base with pHeader declared first
 *           (that one costs 24 B — pHeader drops to r5, so the dedicated
 *           buf local is required). Floor stays 10 B. DWARF confirms the
 *           vendor's i is r12 (int) for the whole function. Needs an allocator
 *           that re-materialises the second zero into ip, which no source
 *           spelling tried reaches.
 * lane 6 (wave 10): named hi/lo/u16 byte temporaries (declared before or after i, five shapes) are inert, still 10 B.
 * lane 8 (wave 8): residue is exactly docs/idioms/a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch.md
 *           (found in CPSi_rc4_init): dsi/1.1p1 hands the freshly-dead asr result r1 to loop 2's hoisted zero,
 *           the image keeps the zero in ip (so the two strb stay in source order). A batch of 10 spellings all pin
 *           at 10 B: hi-first source order, named hi / lo+hi, byte-pointer header, enum zero, named-zero copy,
 *           plain `i < size` loop2 (65 B), `sum / 256` (11 B), `unsigned char i` (124 B). Confirms the idiom's park.
 * lane 7 (wave 8): a full sweep of all 120 declaration orders of {p,sum,i,buf,pHeader} is inert (best stays the
 *           baseline order at 10 B). Making the second zero a dependency of a live value (`z=0; i=z;`,
 *           `i=size-size;`, `i=(unsigned char)(sum&0)`) is inert. Loop2 with a plain/while/do-while condition
 *           changes size; only the ternary bottom-test condition reproduces the shape. Floor remains 10 B.
 * 2026-10-01: DWARF has no buf. Without it (one sIrcBuf symbol, `&sIrcBuf[4]`,
 *           p reused as loop-2 base, or loop 2 as an inline helper with its own
 *           buf/size/i) loop 1's i leaves ip or pHeader/p swap r5/r6; best stays
 *           this body at 10 B.
 *
 * lane 19 (2026-10-01): mechanism found, not fileable under house rules. Adding
 *           `#pragma opt_lifetimes off` to this exact body gives EXACT (152 B): the image keeps
 *           i as one register across both loops (no live-range split), so loop 2's zero is ip.
 *           Plain `for` loops plus a zero-byte asm also give EXACT (asm mode = no rotation +
 *           no lifetimes). Same pair closes MBi_SendVolatBeacon (ov107 021F42D4). Left for the
 *           integrator: no plain-C spelling found that stops the split.
 * Closed 2026-10-01 with `#pragma opt_lifetimes off` (lifetime splitting off), read as
 *   the vendor's build setting for this object, not a workaround. Evidence: across all 67
 *   open overlay SDK drafts the pragma closes exactly three, all from libirc irc.o /
 *   irc_internal.o and libmb mb_gameinfo.o; all 20 already-matched functions of those
 *   objects stay EXACT with it, while it breaks 5 of 125 sampled functions from other
 *   objects. Without it the loop variable is split across two registers (residue noted below).
 * sdk:      IRCi_Send (libirc.a irc.o)
 *
 * symbols:
 *   IRCi_CalcSum  0x02179EE0  arm  ov015
 *   IRCi_Write  0x0217A8EC  arm  ov015
 *   gIrcBuffer     0x0217ABD8  data
 *   gIrcBufferPayload     0x0217ABDC  data
 */

#pragma opt_lifetimes off


typedef struct {
    unsigned char command;
    unsigned char id;
    unsigned char sumLo;
    unsigned char sumHi;
} IRCHeader;

extern unsigned short IRCi_CalcSum(void *input, unsigned long length);
extern void IRCi_Write(unsigned char *data, unsigned char size);
extern unsigned char gIrcBuffer[184];
extern unsigned char gIrcBufferPayload[184];

void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id)
{
    unsigned char *p;
    unsigned short sum;
    int i;
    unsigned char *buf;
    IRCHeader *pHeader;

    pHeader = (IRCHeader *)gIrcBuffer;
    pHeader->command = command;
    pHeader->id = id;
    pHeader->sumLo = 0;
    pHeader->sumHi = 0;
    p = gIrcBufferPayload;
    for (i = 0; (i < size) ? 1 : 0; i++)
        *p++ = *data++;
    size += 4;
    buf = gIrcBuffer;
    sum = IRCi_CalcSum(buf, size);
    pHeader->sumLo = sum;
    pHeader->sumHi = sum >> 8;
    for (i = 0; (i < size) ? 1 : 0; i++)
        buf[i] ^= 0xAA;
    IRCi_Write(gIrcBuffer, size);
}
