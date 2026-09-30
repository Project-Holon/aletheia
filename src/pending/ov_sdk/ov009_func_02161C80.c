/*
 * function: parse_record_in_buf
 * address:  0x02161C80
 * packet:   pkt_ov009_02161C80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen, register allocation only.  Size matches (792 B); ~260
 *           concrete bytes differ, all in the handshake loop (case 0x16).
 *           The whole prologue, make_plaintext gate, and outer switch match
 *           byte for byte once `s` is declared before `len`/`type` (that
 *           pins the vendor's type/s=r5, len=r6), `sub` is `unsigned int`
 *           (else buf leaves sl), and the sub-record length expression is
 *           parenthesised `((s[1] << 16) + (s[2] << 8)) + s[3]`.
 *           Residue: the vendor keeps the sub-record length sub=r8 with its
 *           +4 temp=r7; ours is the mirror (sub=r7, temp=r8), so the loop
 *           head schedules s[2] first and reads the record type with
 *           `ldrb r0,[r5,#-4]` after the pointer advance instead of
 *           `ldrb r0,[r5]` before it.  Declaration order (sub first/last,
 *           s first), `sub` as int/unsigned/long and a named sub+4 temp
 *           were all tried; the r7/r8 swap survives.
 *
 * sdk:      parse_record_in_buf (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   make_plaintext           0x02161784  arm  ov009
 *   MI_CpuFill8              0x02082BCC  arm
 *   client_hello             0x02160EE0  arm  ov009
 *   rcv_client_key_exchange  0x02161480  arm  ov009
 *   rcv_server_hello         0x02160C9C  arm  ov009
 *   rcv_certificate          0x02160A7C  arm  ov009
 *   rcv_finished             0x02161678  arm  ov009
 *   update_digest            0x02161C54  arm  ov009
 *   CPSiFree                 0x021A82B0  data

 * lane U62 (2026-09-30): re-measured 792/792 bytes, 260 concrete (87 sites), unchanged.
 *           Divergence is still codegen-only: the handshake loop's `sub`/`+4` temp pair is
 *           r8/r7 in the image and r7/r8 here, so the loop head reads s[2] first and the record
 *           type with `ldrb r0,[r5,-4]` after the advance instead of `ldrb r0,[r5]` before it.
 *           Measured inert this lane: nothing new applies (no memcpy/memset intrinsic in the
 *           divergent region, no pooled zero, no volatile). Parked.
 */

struct _CPSSslConnection {
    unsigned char pad0[0x1d4];
    unsigned int f1d4;
    unsigned char pad1[0x2e4 - 0x1d4 - 4];
    unsigned char f2e4[8];
    unsigned char pad2[0x454 - 0x2e4 - 8];
    unsigned char f454;
    unsigned char state;
    unsigned char f456;
    unsigned char pad3[0x5ac - 0x457];
    unsigned char f5ac;
    unsigned char pad4[0x824 - 0x5ad];
    unsigned long f824;
    unsigned long f828;
    unsigned long f82c;
};

extern int make_plaintext(struct _CPSSslConnection *con, unsigned char *s);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void client_hello(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_client_key_exchange(struct _CPSSslConnection *con,
                                    unsigned char *s);
extern void rcv_server_hello(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_certificate(struct _CPSSslConnection *con, unsigned char *s);
extern void rcv_finished(struct _CPSSslConnection *con, unsigned char *s);
extern void update_digest(struct _CPSSslConnection *con, unsigned char *s,
                          unsigned long len);
extern void (*CPSiFree)(void *ptr);

static void parse_record_in_buf(struct _CPSSslConnection *con, unsigned char *buf)
{
    unsigned char *s;
    unsigned long len;
    unsigned char type;
    unsigned int sub;

    if (con->state == 9) {
        CPSiFree(buf);
        return;
    }

    len = (buf[3] << 8) + buf[4] + 5;
    type = buf[0];
    if (con->f1d4 != 0 &&
        (((unsigned char)(con->state + 0xf9) <= 1 && type != 0x15) ||
         (type == 0x15 && len > 7))) {
        len = make_plaintext(con, buf);
        if (con->state == 9) {
            CPSiFree(buf);
            return;
        }
    }

    s = buf + 5;
    len -= 5;

    switch (type) {
    case 0x14:
        if (con->f1d4 == 0) {
            con->state = 9;
        } else {
            MI_CpuFill8(con->f2e4, 0, 8);
            con->state = 7;
        }
        break;
    case 0x15:
        if (len != 2 || s[0] == 2)
            con->state = 9;
        break;
    case 0x16:
        if (len < 4) {
            con->state = 9;
            break;
        }
        do {
            sub = ((s[1] << 16) + (s[2] << 8)) + s[3];
            if (sub > len) {
                con->state = 9;
                break;
            }
            s += 4;
            switch (s[-4]) {
            case 1:
                if (con->f454 != 0 && con->state == 0)
                    client_hello(con, s);
                else
                    con->state = 9;
                break;
            case 2:
                if (sub >= 0x26 && con->f454 != 0)
                    con->state = 9;
                else
                    rcv_server_hello(con, s);
                break;
            case 0xb:
                if (con->state == 2 && con->f454 == 0) {
                    rcv_certificate(con, s);
                    con->f5ac = 0;
                } else {
                    con->state = 9;
                }
                break;
            case 0xd:
                if (con->state == 3 && con->f454 == 0)
                    con->f5ac = 1;
                else
                    con->state = 9;
                break;
            case 0xe:
                if (con->f454 == 0 && con->state == 3)
                    con->state = 4;
                else
                    con->state = 9;
                break;
            case 0x10:
                if (con->f454 == 0)
                    con->state = 9;
                else
                    rcv_client_key_exchange(con, s);
                break;
            case 0x14:
                rcv_finished(con, s);
                break;
            default:
                con->state = 9;
                break;
            }
            if (con->state != 9) {
                update_digest(con, s - 4, sub + 4);
                s += sub;
                len -= sub + 4;
            }
        } while (len != 0 && con->state != 9);
        break;
    case 0x17:
        if (con->state != 8) {
            con->state = 9;
        } else {
            con->f824 = (unsigned long)buf;
            con->f82c = 5;
            con->f828 = len + 5;
            con->f456 = 1;
            return;
        }
        break;
    default:
        con->state = 9;
        break;
    }
    CPSiFree(buf);
}


