#ifndef ALETHEIA_G_CARDPULLEDOUTSTATE_H
#define ALETHEIA_G_CARDPULLEDOUTSTATE_H
/* CARDiSlotResetCount (arm9) */
struct CARDPulledOutState {
    void *slot_reset_count;
    void *is_pulled_out;
    int (*callback)(void);
};
#endif
