///search:
void CPythonTextTail::RegisterChatTail(DWORD VirtualID, const char * c_szChat)
{
	CInstanceBase * pCharacterInstance = CPythonCharacterManager::Instance().GetInstancePtr(VirtualID);

	if (!pCharacterInstance)
		return;

	TChatTailMap::iterator itor = m_ChatTailMap.find(VirtualID);

///add:
	std::string strContent = c_szChat;

	char text[69][69] = {":**", "O:)", "~X(", "=D>", ">3", "X(", ";;)",
		";))", "\:D/", ":^>", ">:/", "=((", ":-c", ":-@",
		":O)", ":-/", ":((", ":D", "8->", ">:)", ":o3",
		":-<", ":-$", "=P~", "(pow)", ":-L", ">:P", ";)",
		"<3", ":!!", "@-)", "^#(^", ":*", ":))", ":^o",
		":X", ":-SS", ":-B", "%-(", "[-(", "^:)^", ":-j",
		":)]", "<:-P", ":P", ":ar!", "[-o<", "\m/", "8-/",
		"=))", "@};-", ":(", "[-x", ":-&", ":-^", "8-}",
		"/-)", ":)", ":>", ":/", "B-)", ":O", "=;",
		":-?", ":-t", ":-w", ":-h"};
	char emoji[69][69] = {"|Eemoji/yahoo/2love|e", "|Eemoji/yahoo/angel|e", "|Eemoji/yahoo/at-wits-end|e", "|Eemoji/yahoo/applause|e", "|Eemoji/yahoo/arrow|e", "|Eemoji/yahoo/angry-or-grumpy|e", "|Eemoji/yahoo/batting-eyelashes|e",
		"|Eemoji/yahoo/giggle-or-hee-hee|e", "|Eemoji/yahoo/dancing|e", "|Eemoji/yahoo/blushing|e", "|Eemoji/yahoo/bring-it-on|e", "|Eemoji/yahoo/broken-heart|e", "|Eemoji/yahoo/call-me|e", "|Eemoji/yahoo/chatterbox|e",
		"|Eemoji/yahoo/clown|e", "|Eemoji/yahoo/confused|e", "|Eemoji/yahoo/crying|e", "|Eemoji/yahoo/big-grin|e", "|Eemoji/yahoo/daydreaming|e", "|Eemoji/yahoo/devil|e", "|Eemoji/yahoo/dog|e",
		"|Eemoji/yahoo/doh!|e", "|Eemoji/yahoo/do-not-tell-anyone|e", "|Eemoji/yahoo/drooling|e", "|Eemoji/yahoo/fortziki|e", "|Eemoji/yahoo/frustrated|e", "|Eemoji/yahoo/phbbbbt-or-upset|e", "|Eemoji/yahoo/beat-up|e",
		"|Eemoji/yahoo/heart|e", "|Eemoji/yahoo/hurry-up|e", "|Eemoji/yahoo/hypnotized|e", "|Eemoji/yahoo/it-was-not-me|e", "|Eemoji/yahoo/kiss|e", "|Eemoji/yahoo/laughing|e", "|Eemoji/yahoo/liar-liar|e",
		"|Eemoji/yahoo/love-struck|e", "|Eemoji/yahoo/nail-biting|e", "|Eemoji/yahoo/nerd|e", "|Eemoji/yahoo/not-listening|e", "|Eemoji/yahoo/not-talking|e", "|Eemoji/yahoo/not-worthy|e", "|Eemoji/yahoo/oh-go-on|e",
		"|Eemoji/yahoo/on-the-phone|e", "|Eemoji/yahoo/party|e", "|Eemoji/yahoo/frustrated-or-sticking-tongue-out|e", "|Eemoji/yahoo/pirate|e", "|Eemoji/yahoo/praying|e", "|Eemoji/yahoo/rocking|e", "|Eemoji/yahoo/rolling-eyes|e",
		"|Eemoji/yahoo/rolling-on-the-floor-laughing|e", "|Eemoji/yahoo/rose|e", "|Eemoji/yahoo/sad-or-frown-face|e", "|Eemoji/yahoo/shame-on-you|e", "|Eemoji/yahoo/sick|e", "|Eemoji/yahoo/whistling|e", "|Eemoji/yahoo/silly|e",
		"|Eemoji/yahoo/sleepy|e", "|Eemoji/yahoo/smile-or-happy-face|e", "|Eemoji/yahoo/smug|e", "|Eemoji/yahoo/straight-face|e", "|Eemoji/yahoo/sunglasses-or-cool|e", "|Eemoji/yahoo/surprised|e", "|Eemoji/yahoo/talk-to-the-hand|e",
		"|Eemoji/yahoo/thinking|e", "|Eemoji/yahoo/time-out|e", "|Eemoji/yahoo/waiting|e", "|Eemoji/yahoo/wave|e"};
	   
	if (strContent.find("http") == std::string::npos)
		for (int i = 0; i < 69; i++)
			boost::algorithm::replace_all(strContent, text[i], emoji[i]);

///search (in the same function):
		pTextTail->pTextInstance->SetValue(c_szChat);

///change:
		pTextTail->pTextInstance->SetValue(strContent.c_str());
		
///search (in the same function):
	TTextTail * pTextTail = RegisterTextTail(VirtualID, c_szChat, pCharacterInstance->GetGraphicThingInstancePtr(), pCharacterInstance->GetGraphicThingInstanceRef().GetHeight() + pCharacterInstance->GetBaseHeight() + 10.0f, c_TextTail_Chat_Color);

///change:
	TTextTail * pTextTail = RegisterTextTail(VirtualID, strContent.c_str(), pCharacterInstance->GetGraphicThingInstancePtr(), pCharacterInstance->GetGraphicThingInstanceRef().GetHeight() + pCharacterInstance->GetBaseHeight() + 10.0f, c_TextTail_Chat_Color);
		

