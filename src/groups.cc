#include "groups.h"

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace redsea {

std::string getLCDchar(int code) {
  assert (code >= 32);
  const std::vector<std::string> char_map ({
      " ","!","\\\"","#","¤","%","&","'","(",")","*","+",",","-",".","/",
      "0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?",
      "@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
      "P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","―","_",
      "‖","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
      "p","q","r","s","t","u","v","w","x","y","z","{","|","}","¯"," ",
      "á","à","é","è","í","ì","ó","ò","ú","ù","Ñ","Ç","Ş","β","¡","Ĳ",
      "â","ä","ê","ë","î","ï","ô","ö","û","ü","ñ","ç","ş","ǧ","ı","ĳ",
      "ª","α","©","‰","Ǧ","ě","ň","ő","π","€","£","$","←","↑","→","↓",
      "º","¹","²","³","±","İ","ń","ű","µ","¿","÷","°","¼","½","¾","§",
      "Á","À","É","È","Í","Ì","Ó","Ò","Ú","Ù","Ř","Č","Š","Ž","Ð","Ŀ",
      "Â","Ä","Ê","Ë","Î","Ï","Ô","Ö","Û","Ü","ř","č","š","ž","đ","ŀ",
      "Ã","Å","Æ","Œ","ŷ","Ý","Õ","Ø","Þ","Ŋ","Ŕ","Ć","Ś","Ź","Ŧ","ð",
      "ã","å","æ","œ","ŵ","ý","õ","ø","þ","ŋ","ŕ","ć","ś","ź","ŧ"," "});
  return char_map[code - 32];
}

std::string getPTYname(int pty) {
  assert (pty >= 0 && pty <= 32);
  const std::vector<std::string> pty_names ({
   "No PTY", "News", "Current Affairs", "Information",
   "Sport", "Education", "Drama", "Cultures",
   "Science", "Varied Speech","Pop Music", "Rock Music",
   "Easy Listening","Light Classics M","Serious Classics","Other Music",
   "Weather & Metr", "Finance", "Children's Progs", "Social Affairs",
   "Religion", "Phone In", "Travel & Touring", "Leisure & Hobby",
   "Jazz Music", "Country Music", "National Music", "Oldies Music",
   "Folk Music", "Documentary", "Alarm Test", "Alarm - Alarm !"
  });
  return pty_names[pty];

}

std::string getCountryString(uint16_t pi, uint16_t ecc) {
  const std::map<uint16_t,std::vector<std::string>> country_codes ({
    {0xA0,{"us","us","us","us","us","us","us","us","us","us","us","--","us","us","--"}},
    {0xA1,{"--","--","--","--","--","--","--","--","--","--","ca","ca","ca","ca","gl"}},
    {0xA2,{"ai","ag","ec","fk","bb","bz","ky","cr","cu","ar","br","bm","an","gp","bs"}},
    {0xA3,{"bo","co","jm","mq","gf","py","ni","--","pa","dm","do","cl","gd","tc","gy"}},
    {0xA4,{"gt","hn","aw","--","ms","tt","pe","sr","uy","kn","lc","sv","ht","ve","--"}},
    {0xA5,{"--","--","--","--","--","--","--","--","--","--","mx","vc","mx","mx","mx"}},
    {0xA6,{"--","--","--","--","--","--","--","--","--","--","--","--","--","--","pm"}},
    {0xD0,{"cm","cf","dj","mg","ml","ao","gq","ga","gn","za","bf","cg","tg","bj","mw"}},
    {0xD1,{"na","lr","gh","mr","st","cv","sn","gm","bi","--","bw","km","tz","et","bg"}},
    {0xD2,{"sl","zw","mz","ug","sz","ke","so","ne","td","gw","zr","ci","tz","zm","--"}},
    {0xD3,{"--","--","eh","--","rw","ls","--","sc","--","mu","--","sd","--","--","--"}},
    {0xE0,{"de","dz","ad","il","it","be","ru","ps","al","at","hu","mt","de","--","eg"}},
    {0xE1,{"gr","cy","sm","ch","jo","fi","lu","bg","dk","gi","iq","gb","ly","ro","fr"}},
    {0xE2,{"ma","cz","pl","va","sk","sy","tn","--","li","is","mc","lt","yu","es","no"}},
    {0xE3,{"ie","ie","tr","mk","tj","--","--","nl","lv","lb","az","hr","kz","se","by"}},
    {0xE4,{"md","ee","kg","--","--","ua","--","pt","si","am","uz","ge","--","tm","ba"}},
    {0xF0,{"au","au","au","au","au","au","au","au","sa","af","mm","cn","kp","bh","my"}},
    {0xF1,{"ki","bt","bd","pk","fj","om","nr","ir","nz","sb","bn","lk","tw","kr","hk"}},
    {0xF2,{"kw","qa","kh","ws","in","mo","vn","ph","jp","sg","mv","id","ae","np","vu"}},
    {0xF3,{"la","th","to","--","--","--","--","--","pg","--","ye","--","--","fm","mn"}}
  });

  std::string result("--");

  uint16_t pi_cc = pi >> 12;

  if (country_codes.find(ecc) != country_codes.end() && pi_cc > 0) {
    result = country_codes.at(ecc).at(pi_cc-1);
  }

  return result;

}

std::string getLanguageString(uint16_t code) {
  std::vector<std::string> languages ({
    "Unknown","Albanian","Breton","Catalan",
    "Croatian","Welsh","Czech","Danish",
    "German","English","Spanish","Esperanto",
    "Estonian","Basque","Faroese","French",
    "Frisian","Irish","Gaelic","Galician",
    "Icelandic","Italian","Lappish","Latin",
    "Latvian","Luxembourgian","Lithuanian","Hungarian",
    "Maltese","Dutch","Norwegian","Occitan",
    "Polish","Portuguese","Romanian","Romansh",
    "Serbian","Slovak","Slovene","Finnish",
    "Swedish","Turkish","Flemish","Walloon",
    "","","","",
    "","","","",
    "","","","",
    "","","","",
    "","","","",
    "Background","","","",
    "","Zulu","Vietnamese","Uzbek",
    "Urdu","Ukrainian","Thai","Telugu",
    "Tatar","Tamil","Tadzhik","Swahili",
    "SrananTongo","Somali","Sinhalese","Shona",
    "Serbo-Croat","Ruthenian","Russian","Quechua",
    "Pushtu","Punjabi","Persian","Papamiento",
    "Oriya","Nepali","Ndebele","Marathi",
    "Moldovian","Malaysian","Malagasay","Macedonian",
    "Laotian","Korean","Khmer","Kazakh",
    "Kannada","Japanese","Indonesian","Hindi",
    "Hebrew","Hausa","Gurani","Gujurati",
    "Greek","Georgian","Fulani","Dari",
    "Churash","Chinese","Burmese","Bulgarian",
    "Bengali","Belorussian","Bambora","Azerbaijan",
    "Assamese","Armenian","Arabic","Amharic"
  });

  std::string result("");
  if (code < languages.size()) {
    result = languages[code];
  }

  return result;
}

std::string getAppName(uint16_t aid) {
  std::map<uint16_t,std::string> oda_apps({
    { 0x0000, "None" },
    { 0x0093, "Cross referencing DAB within RDS" },
    { 0x0BCB, "Leisure & Practical Info for Drivers" },
    { 0x0C24, "ELECTRABEL-DSM 7" },
    { 0x0CC1, "Wireless Playground broadcast control signal" },
    { 0x0D45, "RDS-TMC: ALERT-C / EN ISO 14819-1" },
    { 0x0D8B, "ELECTRABEL-DSM 18" },
    { 0x0E2C, "ELECTRABEL-DSM 3" },
    { 0x0E31, "ELECTRABEL-DSM 13" },
    { 0x0F87, "ELECTRABEL-DSM 2" },
    { 0x125F, "I-FM-RDS for fixed and mobile devices" },
    { 0x1BDA, "ELECTRABEL-DSM 1" },
    { 0x1C5E, "ELECTRABEL-DSM 20" },
    { 0x1C68, "ITIS In-vehicle data base" },
    { 0x1CB1, "ELECTRABEL-DSM 10" },
    { 0x1D47, "ELECTRABEL-DSM 4" },
    { 0x1DC2, "CITIBUS 4" },
    { 0x1DC5, "Encrypted TTI using ALERT-Plus" },
    { 0x1E8F, "ELECTRABEL-DSM 17" },
    { 0x4AA1, "RASANT" },
    { 0x4AB7, "ELECTRABEL-DSM 9" },
    { 0x4BA2, "ELECTRABEL-DSM 5" },
    { 0x4BD7, "RadioText+ (RT+)" },
    { 0x4C59, "CITIBUS 2" },
    { 0x4D87, "Radio Commerce System (RCS)" },
    { 0x4D95, "ELECTRABEL-DSM 16" },
    { 0x4D9A, "ELECTRABEL-DSM 11" },
    { 0x5757, "Personal weather station" },
    { 0x6552, "Enhanced RadioText (eRT)" },
    { 0x7373, "Enhanced early warning system" },
    { 0xC350, "NRSC Song Title and Artist" },
    { 0xC3A1, "Personal Radio Service" },
    { 0xC3B0, "iTunes Tagging" },
    { 0xC3C3, "NAVTEQ Traffic Plus" },
    { 0xC4D4, "eEAS" },
    { 0xC549, "Smart Grid Broadcast Channel" },
    { 0xC563, "ID Logic" },
    { 0xC6A7, "Veil Enabled Interactive Device" },
    { 0xC737, "Utility Message Channel (UMC)" },
    { 0xCB73, "CITIBUS 1" },
    { 0xCB97, "ELECTRABEL-DSM 14" },
    { 0xCC21, "CITIBUS 3" },
    { 0xCD46, "RDS-TMC: ALERT-C" },
    { 0xCD47, "RDS-TMC: ALERT-C" },
    { 0xCD9E, "ELECTRABEL-DSM 8" },
    { 0xCE6B, "Encrypted TTI using ALERT-Plus" },
    { 0xE123, "APS Gateway" },
    { 0xE1C1, "Action code" },
    { 0xE319, "ELECTRABEL-DSM 12" },
    { 0xE411, "Beacon downlink" },
    { 0xE440, "ELECTRABEL-DSM 15" },
    { 0xE4A6, "ELECTRABEL-DSM 19" },
    { 0xE5D7, "ELECTRABEL-DSM 6" },
    { 0xE911, "EAS open protocol" }
  });

  std::string result("");
  if (oda_apps.find(aid) != oda_apps.end()) {
    result = oda_apps[aid];
  }

  return result;
}

GroupType::GroupType(uint16_t type_code) : num((type_code >> 1) & 0xF), ab(type_code & 0x1) {}
GroupType::GroupType(const GroupType& obj) : num(obj.num), ab(obj.ab) {}

std::string GroupType::toString() {
  return std::string(std::to_string(num) + (ab == TYPE_A ? "A" : "B"));
}

bool operator==(const GroupType& obj1, const GroupType& obj2) {
  return (obj1.num == obj2.num && obj1.ab == obj2.ab);
}

bool operator<(const GroupType& obj1, const GroupType& obj2) { return ((obj1.num < obj2.num) || (obj1.ab < obj2.ab)); }

// extract len bits from bitstring, starting at starting_at from the right
uint16_t bits (uint16_t bitstring, int starting_at, int len) {
  return ((bitstring >> starting_at) & ((1<<len) - 1));
}

RDSString::RDSString(int len) : chars_(len), is_char_sequential_(len), prev_pos_(-1) {
  last_complete_string_ = getString();
}

void RDSString::setAt(int pos, int chr) {
  if (pos < 0 || pos >= (int)chars_.size())
    return;

  chars_[pos] = chr;

  if (pos != prev_pos_ + 1) {
    for (size_t i=0; i<is_char_sequential_.size(); i++)
      is_char_sequential_[i] = false;
  }

  is_char_sequential_[pos] = true;

  if (isComplete())
    last_complete_string_ = getString();

  prev_pos_ = pos;

}

size_t RDSString::lengthReceived() const {

  size_t result = 0;
  for (size_t i=0; i<is_char_sequential_.size(); i++) {
    if (!is_char_sequential_[i])
      break;
    result = i+1;
  }

  return result;
}

size_t RDSString::lengthExpected() const {

  size_t result = chars_.size();

  for (size_t i=0; i<chars_.size(); i++) {
    if (chars_[i] == 0x0D) {
      result = i;
      break;
    }
  }

  return result;
}

std::string RDSString::getString() const {
  std::string result;
  size_t len = lengthExpected();
  for (size_t i=0; i<len; i++) {
    result += (is_char_sequential_[i] ? getLCDchar(chars_[i]) : " ");
  }

  return result;

}


std::string RDSString::getLastCompleteString() const {
  return last_complete_string_;
}

bool RDSString::isComplete() const {
  return lengthReceived() >= lengthExpected();
}

void RDSString::clear() {
  for (size_t i=0; i<chars_.size(); i++) {
    is_char_sequential_[i] = false;
  }
  last_complete_string_ = getString();
}

Station::Station() : Station(0x0000) {

}

Station::Station(uint16_t _pi) : pi_(_pi), ps_(8), rt_(64) {

}

void Station::update(Group group) {

  is_tp_   = bits(group.block2, 10, 1);
  pty_     = bits(group.block2,  5, 5);

  printf("{ pi: \"0x%04x\", group: \"%s\", ", pi_, group.type.toString().c_str());

  printf("tp: %s, ", is_tp_ ? "true" : "false");
  printf("prog_type: \"%s\", ", getPTYname(pty_).c_str());

  if      (group.type.num == 0)  { decodeType0(group); }
  else if (group.type.num == 1)  { decodeType1(group); }
  else if (group.type.num == 2)  { decodeType2(group); }
  else if (group.type.num == 3)  { decodeType3(group); }
  else if (group.type.num == 4)  { decodeType4(group); }
  else if (group.type.num == 8)  { decodeType8(group); }
  else if (group.type.num == 14) { decodeType14(group); }
  else                           { printf("/* TODO */ "); }

  printf("}\n");
}

void Station::addAltFreq(uint8_t af_code) {
  if (af_code >= 1 && af_code <= 204) {
    alt_freqs_.insert(87.5 + af_code / 10.0);
  } else if (af_code == 205) {
    // filler
  } else if (af_code == 224) {
    // no AF exists
  } else if (af_code >= 225 && af_code <= 249) {
    num_alt_freqs_ = af_code - 224;
  } else if (af_code == 250) {
    // AM/LF freq follows
  }
}

bool Station::hasPS() const {
  return ps_.isComplete();
}

std::string Station::getPS() const {
  return ps_.getLastCompleteString();
}

std::string Station::getRT() const {
  return rt_.getLastCompleteString();
}

uint16_t Station::getPI() const {
  return pi_;
}

std::string Station::getCountryCode() const {
  return getCountryString(pi_, ecc_);
}

void Station::updatePS(int pos, std::vector<int> chars) {

  for (int i=pos; i<pos+(int)chars.size(); i++)
    ps_.setAt(i, chars[i-pos]);

  if (ps_.isComplete())
    printf("ps: \"%s\", ",ps_.getLastCompleteString().c_str());

}

void Station::updateRadioText(int pos, std::vector<int> chars) {

  for (int i=pos; i<pos+(int)chars.size(); i++)
    rt_.setAt(i, chars[i-pos]);

  if (rt_.isComplete())
    printf("radiotext: \"%s\", ",rt_.getLastCompleteString().c_str());

}

void Station::decodeType0 (Group group) {

  // not implemented: Decoder Identification

  is_ta_    = bits(group.block2, 4, 1);
  is_music_ = bits(group.block2, 3, 1);

  printf("ta: %s, ", is_ta_ ? "true" : "false");

  if (group.num_blocks < 3)
    return;

  if (group.type.ab == TYPE_A) {
    for (int i=0; i<2; i++) {
      addAltFreq(bits(group.block3, 8-i*8, 8));
    }

    if ((int)alt_freqs_.size() == num_alt_freqs_) {
      printf("alt_freqs: [ ");
      for (auto f : alt_freqs_)
        printf("%.1f, ", f);
      printf("], ");
      alt_freqs_.clear();
    }
  }

  if (group.num_blocks < 4)
    return;

  updatePS(bits(group.block2, 0, 2) * 2,
      { bits(group.block4, 8, 8), bits(group.block4, 0, 8) });

}

void Station::decodeType1 (Group group) {

  if (group.num_blocks < 4)
    return;

  pin_ = group.block4;

  if (group.type.ab == TYPE_A) {
    pager_tng_ = bits(group.block2, 2, 3);
    if (pager_tng_ != 0) {
      pager_interval_ = bits(group.block2, 0, 2);
    }
    linkage_la_ = bits(group.block3, 15, 1);

    int slc_variant = bits(group.block3, 12, 3);

    if (slc_variant == 0) {
      if (pager_tng_ != 0) {
        pager_opc_ = bits(group.block3, 8, 4);
      }

      // No PIN, section M.3.2.4.3
      if (group.num_blocks == 4 && (group.block4 >> 11) == 0) {
        int subtype = bits(group.block4, 10, 1);
        if (subtype == 0) {
          if (pager_tng_ != 0) {
            pager_pac_ = bits(group.block4, 4, 6);
            pager_opc_ = bits(group.block4, 0, 4);
          }
        } else if (subtype == 1) {
          if (pager_tng_ != 0) {
            int b = bits(group.block4, 8, 2);
            if (b == 0) {
              pager_ecc_ = bits(group.block4, 0, 6);
            } else if (b == 3) {
              pager_ccf_ = bits(group.block4, 0, 4);
            }
          }
        }
      }

      ecc_ = bits(group.block3,  0, 8);
      cc_  = bits(group.block1, 12, 4);

      if (ecc_ != 0x00) {
        has_country_ = true;

        printf("country: \"%s\", ", getCountryString(pi_, ecc_).c_str());
      }

    } else if (slc_variant == 1) {
      tmc_id_ = bits(group.block3, 0, 12);
      printf("tmc_id: \"0x%03x\", ", tmc_id_);

    } else if (slc_variant == 2) {
      if (pager_tng_ != 0) {
        pager_pac_ = bits(group.block3, 0, 6);
        pager_opc_ = bits(group.block3, 8, 4);
      }

      // No PIN, section M.3.2.4.3
      if (group.num_blocks == 4 && (group.block4 >> 11) == 0) {
        int subtype = bits(group.block4, 10, 1);
        if (subtype == 0) {
          if (pager_tng_ != 0) {
            pager_pac_ = bits(group.block4, 4, 6);
            pager_opc_ = bits(group.block4, 0, 4);
          }
        } else if (subtype == 1) {
          if (pager_tng_ != 0) {
            int b = bits(group.block4, 8, 2);
            if (b == 0) {
              pager_ecc_ = bits(group.block4, 0, 6);
            } else if (b == 3) {
              pager_ccf_ = bits(group.block4, 0, 4);
            }
          }
        }
      }

    } else if (slc_variant == 3) {
      lang_ = bits(group.block3, 0, 8);
      printf("language: \"%s\", ", getLanguageString(lang_).c_str());

    } else if (slc_variant == 6) {
      // TODO:
      // broadcaster data

    } else if (slc_variant == 7) {
      ews_channel_ = bits(group.block3, 0, 12);
      printf("ews: \"0x%03x\", ", ews_channel_);
    }

  }

}

void Station::decodeType2 (Group group) {

  if (group.num_blocks < 3)
    return;

  int rt_position = bits(group.block2, 0, 4) * (group.type.ab == TYPE_A ? 4 : 2);
  int prev_textAB = rt_ab_;
  rt_ab_          = bits(group.block2, 4, 1);

  if (prev_textAB != rt_ab_)
    rt_.clear();

  std::string chars;

  if (group.type.ab == TYPE_A) {
    updateRadioText(rt_position, {bits(group.block3, 8, 8), bits(group.block3, 0, 8)});
  }

  if (group.num_blocks == 4) {
    updateRadioText(rt_position+2, {bits(group.block4, 8, 8), bits(group.block4, 0, 8)});
  }

}

void Station::decodeType4 (Group group) {

  if (group.num_blocks < 3 || group.type.ab == TYPE_B)
    return;

  int mjd = (bits(group.block2, 0, 2) << 15) + bits(group.block3, 1, 15);
  double lto;

  if (group.num_blocks == 4) {
    lto = (bits(group.block4, 5, 1) ? -1 : 1) * bits(group.block4, 0, 5) / 2.0;
    mjd = int(mjd + lto / 24.0);
  }

  int yr = int((mjd - 15078.2) / 365.25);
  int mo = int((mjd - 14956.1 - int(yr * 365.25)) / 30.6001);
  int dy = mjd - 14956 - int(yr * 365.25) - int(mo * 30.6001);
  if (mo == 14 || mo == 15) {
    yr += 1;
    mo -= 12;
  }
  yr += 1900;
  mo -= 1;

  if (group.num_blocks == 4) {
    int ltom = (lto - int(lto)) * 60;

    int hr = int((bits(group.block3, 0, 1) << 4) +
        bits(group.block4, 12, 14) + lto) % 24;
    int mn = bits(group.block4, 6, 6) + ltom;

    char buff[100];
    snprintf(buff, sizeof(buff),
        "%04d-%02d-%02dT%02d:%02d:00%+03d:%02d",yr,mo,dy,hr,mn,int(lto),ltom);
    clock_time_ = buff;
    printf("clock_time: \"%s\", ", clock_time_.c_str());

  }
}

void Station::decodeType14 (Group group) {

}

} // namespace redsea
