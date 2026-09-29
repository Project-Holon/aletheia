typedef unsigned char u8;
typedef unsigned short u16;
typedef volatile u16 vu16;

typedef struct {
    char pad0[0x30];
    u16 cont;
    u16 trg;
    u16 rep;
    u16 rel;
} Pad;

typedef struct {
    int pad0;
    Pad *pad;
} Fold;

extern Fold g_021DE688;
extern u8 g_021DE690[14];

void func_021D657C(void)
{
    vu16 *input;
    u16 key;
    int i;
    u16 bit;

    u16 raw;

    input = (vu16 *)0x04000130;
    raw = (u16)(((*input | *(vu16 *)0x02ffffa8) ^ 0x2fff) & 0x2fff);
    key = (u16)(raw & ~((raw & 0x40) << 1) & ~((raw & 0x20) >> 1));
    g_021DE688.pad->trg = (g_021DE688.pad->cont ^ key) & key;
    g_021DE688.pad->rel = g_021DE688.pad->cont & (g_021DE688.pad->cont ^ key);
    g_021DE688.pad->cont = key;
    g_021DE688.pad->rep = g_021DE688.pad->trg;
    for (i = 0; i < 14; i++) {
        bit = (u16)(1 << i);
        if (key & bit) {
            g_021DE690[i]++;
            if (g_021DE690[i] == 40) {
                g_021DE688.pad->rep |= bit;
            } else if (g_021DE690[i] == 47) {
                g_021DE690[i] = 40;
                g_021DE688.pad->rep |= bit;
            }
        } else {
            g_021DE690[i] = 0;
        }
    }
}
