#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
 
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
 
  generateSoundex("gokul", soundex);
  ASSERT_STREQ(soundex,"G240");

  generateSoundex("good", soundex);
  ASSERT_STREQ(soundex,"G300"); 

  generateSoundex("hwyaeiou", soundex);
  ASSERT_STREQ(soundex,"H000");

  generateSoundex("qwertyuiop", soundex);
  ASSERT_STREQ(soundex,"Q630");

  generateSoundex("abcde", soundex);
  ASSERT_STREQ(soundex,"A123");
 
  generateSoundex("dessert", soundex);
  ASSERT_STREQ(soundex,"D263");
}
