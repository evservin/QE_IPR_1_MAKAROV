#ifndef VUSER_WEBSOCKET_BUFFER_HEADER
#define VUSER_WEBSOCKET_BUFFER_HEADER

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive0[] = "{\"operation\":\"ping\",\"server-interval-sec\":60,\"message\":\"\"}";
long WebSocketReceiveLen0   = sizeof(WebSocketReceive0) - 1;	// (record-time: 58 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive1[] = "{\"operation\":\"ping\",\"server-interval-sec\":60,\"message\":\"\"}";
long WebSocketReceiveLen1   = sizeof(WebSocketReceive1) - 1;	// (record-time: 58 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive2[] = "{\"version\":\"1\",\"uid\":\"1431766764\",\"service\":\"mail\",\"operation\":\"u"
                        "nsupported\",\"lcn\":\"182\",\"session_key\":\"LIZA-95430491-1641556518451\",\"s"
                        "erver_notify_id\":\"PuTT8CVD14Y1:RuTkDGTEx4Y1.PuTpdAUgTa61_move_mails_http_webpu"
                        "sh_websocket:u2709:mail\",\"bright\":true,\"message\":{\"fid\":\"-1\",\"lcn\":\""
                        "182\",\"mids\":\"[\\\"178173660257845346\\\"]\",\"operation\":\"move mails\",\"s"
                        "ession_key\":\"LIZA-95430491-1641556518451\",\"uid\":\"1431766764\",\"uname\":\""
                        "1768043446\"},\"raw_data\":\"{\\\"uid\\\":\\\"1431766764\\\",\\\"uname\\\":\\\"1"
                        "768043446\\\",\\\"lcn\\\":\\\"182\\\",\\\"operation\\\":\\\"move mails\\\",\\\"f"
                        "id\\\":-1,\\\"sessionKey\\\":\\\"LIZA-95430491-1641556518451\\\",\\\"mids_str\\\""
                        ":\\\"[\\\\\\\"178173660257845346\\\\\\\"]\\\"}\",\"tags\":[],\"position\":48}";
long WebSocketReceiveLen2   = sizeof(WebSocketReceive2) - 1;	// (record-time: 666 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive3[] = "{\"version\":\"1\",\"uid\":\"1431766764\",\"service\":\"mail\",\"operation\":\"u"
                        "nsupported\",\"lcn\":\"182\",\"session_key\":\"LIZA-95430491-1641556518451\",\"s"
                        "erver_notify_id\":\"PuTRACVDx0U1:RuTi3IRALW21.PuTpdAUgTa61_delete_mails_http_web"
                        "push_websocket:u2709:mail\",\"bright\":true,\"message\":{\"lcn\":\"182\",\"opera"
                        "tion\":\"delete mails\",\"session_key\":\"LIZA-95430491-1641556518451\"},\"raw_d"
                        "ata\":\"{\\\"uid\\\":\\\"1431766764\\\",\\\"uname\\\":\\\"1768043446\\\",\\\"lcn"
                        "\\\":\\\"182\\\",\\\"operation\\\":\\\"delete mails\\\",\\\"sessionKey\\\":\\\"L"
                        "IZA-95430491-1641556518451\\\",\\\"mids\\\":[\\\"178173660257845346\\\"]}\",\"ta"
                        "gs\":[],\"position\":49}";
long WebSocketReceiveLen3   = sizeof(WebSocketReceive3) - 1;	// (record-time: 564 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive4[] = "{\"version\":\"1\",\"uid\":\"1431766764\",\"service\":\"mail\",\"operation\":\"i"
                        "nsert\",\"lcn\":\"183\",\"session_key\":\"\",\"server_notify_id\":\"MuTquBVDxiE1"
                        ":RuTW4UQB8Os1.PuTxdAUgT0U1_insert_http_webpush_websocket:u2709:mail\",\"bright\""
                        ":true,\"message\":{\"fid\":\"4\",\"fid_type\":\"2\",\"firstline\":\"test55555\","
                        "\"fresh_count\":\"0\",\"hdr_from\":\"\\\"C"
                        "\xd0\xb0\xd1\x88\xd0\xb0"
                        " "
                        "\xd0\x9c\xd0\xb0\xd0\xba\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2"
                        "\\\" <cashamakarov@yandex.ru>\",\"hdr_message_id\":\"<4220181641556539@mail.yand"
                        "ex.ru>\",\"hdr_status\":\"RO\",\"hdr_subject\":\"No subject\",\"hdr_to\":\"\\\"a"
                        "leksandr.makarov.1995@mail.ru\\\" <aleksandr.makarov.1995@mail.ru>\",\"lcn\":\"1"
                        "83\",\"lid\":\"12,15,16,FAKE_RECENT_LBL,FAKE_SEEN_LBL\",\"mid\":\"17817366025784"
                        "5347\",\"new_messages\":\"20\",\"operation\":\"insert\",\"received_date\":\"07.0"
                        "1.2022 14:56:25\",\"sz\":\"1845\",\"thread_id\":\"178173660257845347\",\"uid\":\""
                        "1431766764\",\"uname\":\"1768043446\"},\"raw_data\":\"{\\\"uid\\\":\\\"143176676"
                        "4\\\",\\\"uname\\\":\\\"1768043446\\\",\\\"lcn\\\":\\\"183\\\",\\\"operation\\\""
                        ":\\\"insert\\\",\\\"sessionKey\\\":\\\"\\\",\\\"fid\\\":\\\"4\\\",\\\"mids_str\\"
                        "\":\\\"[\\\\\\\"178173660257845347\\\\\\\"]\\\",\\\"threadId\\\":\\\"17817366025"
                        "7845347\\\",\\\"newCount\\\":20,\\\"status\\\":\\\"RO\\\",\\\"freshCount\\\":0,\\"
                        "\"mid\\\":\\\"178173660257845347\\\",\\\"loc-args\\\":[\\\"C"
                        "\xd0\xb0\xd1\x88\xd0\xb0"
                        " "
                        "\xd0\x9c\xd0\xb0\xd0\xba\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2"
                        "\\\",\\\"No subject\\\",\\\"test55555\\\"],\\\"counters\\\":[1,22,2,2,4,42,6,13]"
                        ",\\\"countersNew\\\":[1,20,2,2],\\\"tab\\\":\\\"\\\",\\\"envelopes\\\":[{\\\"fid"
                        "\\\":\\\"4\\\",\\\"fidType\\\":2,\\\"firstline\\\":\\\"test55555\\\",\\\"from\\\""
                        ":[{\\\"local\\\":\\\"cashamakarov\\\",\\\"domain\\\":\\\"yandex.ru\\\",\\\"displ"
                        "ayName\\\":\\\"C"
                        "\xd0\xb0\xd1\x88\xd0\xb0"
                        " "
                        "\xd0\x9c\xd0\xb0\xd0\xba\xd0\xb0\xd1\x80\xd0\xbe\xd0\xb2"
                        "\\\"}],\\\"subject\\\":\\\"No subject\\\",\\\"to\\\":[{\\\"local\\\":\\\"aleksan"
                        "dr.makarov.1995\\\",\\\"domain\\\":\\\"mail.ru\\\",\\\"displayName\\\":\\\"aleks"
                        "andr.makarov.1995@mail.ru\\\"}],\\\"types\\\":[4,55],\\\"labels\\\":[\\\"12\\\","
                        "\\\"15\\\",\\\"16\\\",\\\"FAKE_RECENT_LBL\\\",\\\"FAKE_SEEN_LBL\\\"],\\\"labelsI"
                        "nfo\\\":{\\\"12\\\":{\\\"symbolicName\\\":{\\\"title\\\":\\\"\\\"}},\\\"15\\\":{"
                        "\\\"symbolicName\\\":{\\\"title\\\":\\\"encrypted_label\\\"}},\\\"16\\\":{\\\"sy"
                        "mbolicName\\\":{\\\"title\\\":\\\"\\\"}},\\\"FAKE_RECENT_LBL\\\":{\\\"symbolicNa"
                        "me\\\":{\\\"title\\\":\\\"recent_label\\\"}},\\\"FAKE_SEEN_LBL\\\":{\\\"symbolic"
                        "Name\\\":{\\\"title\\\":\\\"seen_label\\\"}}},\\\"mid\\\":\\\"178173660257845347"
                        "\\\",\\\"date\\\":1641556585,\\\"size\\\":1845,\\\"threadId\\\":\\\"178173660257"
                        "845347\\\",\\\"messageId\\\":\\\"<4220181641556539@mail.yandex.ru>\\\",\\\"tab\\"
                        "\":\\\"\\\"}]}\",\"tags\":[],\"position\":50}";
long WebSocketReceiveLen4   = sizeof(WebSocketReceive4) - 1;	// (record-time: 2137 bytes)

#endif
