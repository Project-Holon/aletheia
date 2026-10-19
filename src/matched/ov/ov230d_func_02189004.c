/*
 * function: OV230_Crc32
 * address:  0x02189004
 * packet:   pkt_ov230d_02189004
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_checks_card.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_Crc32  0x02189004  arm  ov230d
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 OV230_Crc32(const u8 *data, u32 size)
{
    u32 crc = 0xFFFFFFFF;

    while (size--) {
        crc ^= *data++;
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
    }
    return ~crc;
}
