#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

//#include "7k2mpa.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _LLOWER 2
#define _RLOWER 3
#define _RAISE 4
#define _NUMPAD 5
#define _MOUSECURSOR 8
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  LLOWER,
  RLOWER,
  RAISE,
  NUMPAD,
  MOUSECURSOR,
  ADJUST,
};



/* Tap Dance */
enum {
  TD_SHIFTCAPS = 0,

  TD_F13LOWER,
  TD_F14LOWER,
  TD_LALTUNLOCK,
  TD_LGUIUNLOCK,
  TD_RAISERAISELOCK,
  TD_RAISELOWERLOCK

};



/* Tap Dance */

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_LLWR LLOWER
#define KC_RLWR RLOWER


#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_MCPW KC_POWER
#define KC_MCVU KC__VOLUP
#define KC_MCVD KC__VOLDOWN


#define KC_TBCT MT(MOD_LCTL, KC_TAB) // tap TAB , Hold LCTL

#define KC_BSAL MT(MOD_LALT, KC_BSPC) // tap BackSpace , Hold LALT

#define KC_BLRS MT(MOD_RSFT, KC_BSLS) // tap BackSlash , Hold RSFT


#define KC_CADL LCA(KC_DEL)
#define KC_STAB S(KC_TAB)


#define KC_ESRA LT(_RAISE,KC_ESC) // tap ESC , Hold RaiseLayer
#define KC_DLRA LT(_RAISE,KC_DEL) // tap Delete , Hold RaiseLayer


/* Tap Dance */
#define KC_SHCP TD(TD_SHIFTCAPS)

#define KC_F14L TD(TD_F14LOWER)
#define KC_F13L TD(TD_F13LOWER)

#define KC_LAUL TD(TD_LALTUNLOCK)
#define KC_LGUL TD(TD_LGUIUNLOCK)

#define KC_DRRL TD(TD_RAISERAISELOCK)
#define KC_ERLL TD(TD_RAISELOWERLOCK)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP, Z  , X  , C  , V  , B  ,ESRA,     DLRA, N  , M  ,COMM,DOT ,SLSH,BLRS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LLWR,TBCT,         BSAL,RLWR,LGUI
  //                  `----+----+----'        `----+----+----'
  ),



  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,UNDS,EQL ,PIPE,LABK,               RABK,PGUP, UP ,PGDN,HOME,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,GRV ,PLUS,MINS,BSLS,LBRC,               RBRC,LEFT,DOWN,RGHT,END ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , RO ,JYEN,QUES,LPRN,LCBR,ERLL,     DRRL,RCBR,RPRN,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LAUL,    ,TAB ,         BSPC,    ,LGUL
  //                  `----+----+----'        `----+----+----'
  ),

  [_LLOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,F14L,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RLOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,F13L,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),



  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----+              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,ENT ,
  //|----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
         ,PLUS,MINS,EQL ,BSLS,QUOT,    ,         ,DQUO,SLSH,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     NLCK,    ,    ,    ,    ,    ,                   , P7 , P8 , P9 ,PMNS,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME,PGUP, UP ,PGDN,LABK,               RABK, P4 , P5 , P6 ,PPLS,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,END ,LEFT,DOWN,RGHT,LPRN,               RPRN, P1 , P2 , P3 ,PAST,COLN,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,STAB,    ,      P0 ,EQL , P0 ,COMM,DOT ,PSLS,PENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSECURSOR] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME,PGUP, UP ,PGDN,NO  ,               WH_D,BTN1,MS_U,BTN2,BTN3,ACL0,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,END ,LEFT,DOWN,RGHT,NO  ,               WH_L,MS_L,MS_D,MS_R,WH_R,ACL1,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,WH_U,LEFT,DOWN, UP ,RGHT,ACL2,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
),


  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     RST ,MUTE,VOLD,VOLU,NO  ,NO  ,               NO  ,NO  ,NO  ,NO  ,NO  ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CADL,NO  ,NO  ,NO  ,NO  ,NO  ,               RTOG,RMOD,RHUI,RSAI,RVAI,NO  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MCPW,EJCT,MCVD,MCVU,NO  ,NO  ,               NO  ,DBUG,RHUD,RSAD,RVAD,NO  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,NO  ,VOLD,VOLU,NO  ,NO  ,    ,         ,NO  ,NO  ,NO  ,NO  ,NO  ,BL_S,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};


/* TAP DANCE */
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_CAPS);
  } else {
    register_code (KC_RSFT);
  }
}

void shift_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_CAPS);
  } else {
    unregister_code (KC_RSFT);
  }
}


void dance_laltunlock_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_LALT);
//        layer_off(_LOWER);
    }
}

void dance_laltunlock_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_LALT);
//        layer_on(_LOWER);
    }
    else
    {
      layer_off(_RAISE);
      layer_off(_LOWER);
      layer_off(_NUMPAD);
      layer_off(_MOUSECURSOR);
    }
}


void dance_lguiunlock_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_LGUI);
//        layer_off(_LOWER);
    }
}

void dance_lguiunlock_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_LGUI);
//        layer_on(_LOWER);
    }
    else
    {
      layer_off(_RAISE);
      layer_off(_LOWER);
      layer_off(_NUMPAD);
      layer_off(_MOUSECURSOR);
    }
}

/*
void F13LOWER_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_F13);
    }
}

void F13LOWER_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_F13);
    }
    else
    {
        uint8_t layer = biton32(layer_state);
        if (layer == _NUMPAD)
        {
            layer_off(_NUMPAD);
        } else {
            layer_on(_NUMPAD);
            layer_off(_MOUSECURSOR);
            layer_off(_LOWER);
            layer_off(_RAISE);
        }
    }
}


void F14LOWER_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_F14);
    }
}

void F14LOWER_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_F14);
    }
    else
    {
        uint8_t layer = biton32(layer_state);
        if (layer == _MOUSECURSOR)
        {
            layer_off(_MOUSECURSOR);
        } else {
            layer_on(_MOUSECURSOR);
            layer_off(_NUMPAD);
            layer_off(_LOWER);
            layer_off(_RAISE);
        }
    }
}

*/

// Tap dance definition
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};




void F13LOWER_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:                     // single tap escape
//        if (IS_LAYER_ON(_LOWER)){
//            layer_off(_LOWER);
//        } else {
        register_code(KC_F13);

//        }
        break;
    case SINGLE_HOLD:                   // hold RAISE layer on
        register_code(KC_SPACE);
        break;
    case DOUBLE_TAP:                    // double tap toggle Lower layer lock
        layer_invert(_NUMPAD); 
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_MOUSECURSOR);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
  }
}

void F13LOWER_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  
        unregister_code(KC_F13);

        break;
    case SINGLE_HOLD: 
        unregister_code(KC_SPACE);        
        break;
    case DOUBLE_TAP:  break;
  }
  xtap_state.state = 0;
}




void F14LOWER_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:                     // single tap escape
//        if (IS_LAYER_ON(_LOWER)){
//            layer_off(_LOWER);
//        } else {
        register_code(KC_F14);

//        }
        break;
    case SINGLE_HOLD:                   // hold RAISE layer on
        register_code(KC_ENTER);
        break;
    case DOUBLE_TAP:                    // double tap toggle Lower layer lock
        layer_invert(_MOUSECURSOR); 
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
  }
}

void F14LOWER_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  
        unregister_code(KC_F14);

        break;
    case SINGLE_HOLD: 
        unregister_code(KC_ENTER);        
        break;
    case DOUBLE_TAP:  break;
  }
  xtap_state.state = 0;
}






void dance_raiselowerlock_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:                     // single tap escape
//        if (IS_LAYER_ON(_LOWER)){
//            layer_off(_LOWER);
//        } else {
        register_code(KC_ESCAPE);

//        }
        break;
    case SINGLE_HOLD:                   // hold RAISE layer on
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        break;
    case DOUBLE_TAP:                    // double tap toggle Lower layer lock
        layer_invert(_LOWER); 
        layer_off(_RAISE);
        layer_off(_MOUSECURSOR);
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
  }
}

void dance_raiselowerlock_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  
        unregister_code(KC_ESCAPE);

        break;
    case SINGLE_HOLD: 
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
    case DOUBLE_TAP:  break;
  }
  xtap_state.state = 0;
}

void dance_raiseraiselock_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:                     // single tap delete
//        if (IS_LAYER_ON(_LOWER)){
//            layer_off(_LOWER);
//        } else {
        register_code(KC_DELETE);

//        }
        break;
    case SINGLE_HOLD:                   // hold RAISE layer on
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
    case DOUBLE_TAP:                    // double tap toggle RAISE layer lock
        layer_invert(_RAISE); 
        layer_off(_LOWER);
        layer_off(_MOUSECURSOR);
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);        
        break;
  }
}

void dance_raiseraiselock_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP:  
        unregister_code(KC_DELETE);

        break;
    case SINGLE_HOLD: 
        layer_off(_RAISE);
        break;
    case DOUBLE_TAP:  break;
  }
  xtap_state.state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {


  // Tap once for Left Shift , trice for CAPS Lock
        [TD_SHIFTCAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_caps_down, shift_caps_up),

        [TD_F13LOWER]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,F13LOWER_finished, F13LOWER_reset),
        [TD_F14LOWER]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,F14LOWER_finished, F14LOWER_reset),

        [TD_LGUIUNLOCK]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_lguiunlock_finished, dance_lguiunlock_reset),
        [TD_LALTUNLOCK]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_laltunlock_finished, dance_laltunlock_reset),

        [TD_RAISELOWERLOCK]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_raiselowerlock_finished, dance_raiselowerlock_reset),
        [TD_RAISERAISELOCK]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,dance_raiseraiselock_finished, dance_raiseraiselock_reset),


};



/* END TAP DANCE */



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool llower_pressed = false;
static uint16_t llower_pressed_time = 0;
static bool rlower_pressed = false;
static uint16_t rlower_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LLOWER:
      if (record->event.pressed) {
        llower_pressed = true;
        llower_pressed_time = record->event.time;

        layer_on(_LLOWER);
        layer_on(_LOWER);
        update_tri_layer(_LLOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LLOWER);
        layer_off(_LOWER);
        update_tri_layer(_LLOWER, _RAISE, _ADJUST);

        if (llower_pressed && (TIMER_DIFF_16(record->event.time, llower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        llower_pressed = false;
      }
      return false;
      break;
    case RLOWER:
      if (record->event.pressed) {
        rlower_pressed = true;
        rlower_pressed_time = record->event.time;

        layer_on(_RLOWER);
        layer_on(_LOWER);
        update_tri_layer(_RLOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RLOWER);
        layer_off(_LOWER);
        update_tri_layer(_RLOWER, _RAISE, _ADJUST);

        if (rlower_pressed && (TIMER_DIFF_16(record->event.time, rlower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
        }
        rlower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flags
        llower_pressed = false;
        rlower_pressed = false;
      }
      break;
  }
  return true;
}


