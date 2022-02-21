#ifndef VUSER_WEBSOCKET_BUFFER_HEADER
#define VUSER_WEBSOCKET_BUFFER_HEADER

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive0[] = "{\"operation\":\"ping\",\"server-interval-sec\":60,\"message\":\"\"}";
long WebSocketReceiveLen0   = sizeof(WebSocketReceive0) - 1;	// (record-time: 58 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive1[] = "{\"operation\":\"ping\",\"server-interval-sec\":60,\"message\":\"\"}";
long WebSocketReceiveLen1   = sizeof(WebSocketReceive1) - 1;	// (record-time: 58 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive2[] = "{\"version\":\"1\",\"uid\":\"1431766764\",\"service\":\"calendar\",\"operation\""
                        ":\"unsubscribe\",\"lcn\":\"\",\"session_key\":\"\",\"server_notify_id\":\"xCe6o1"
                        "EA3Gk1:EDehNu8ae8c1:u2709:calendar\",\"bright\":true,\"message\":\"{\\\"event\\\""
                        ":\\\"unsubscribe\\\",\\\"reason\\\":\\\"session.invalidate\\\"}\",\"tags\":[],\""
                        "position\":0}";
long WebSocketReceiveLen2   = sizeof(WebSocketReceive2) - 1;	// (record-time: 280 bytes)

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

char WebSocketReceive3[] = "{\"version\":\"1\",\"uid\":\"1431766764\",\"service\":\"mail\",\"operation\":\"u"
                        "nsupported\",\"lcn\":\"\",\"session_key\":\"\",\"server_notify_id\":\"7Degb2EA68"
                        "c1:EDehNu8ae8c1:u2709:mail\",\"bright\":true,\"raw_data\":\"{\\\"event\\\":\\\"u"
                        "nsubscribe\\\",\\\"reason\\\":\\\"session.invalidate\\\"}\",\"tags\":[],\"positi"
                        "on\":0}";
long WebSocketReceiveLen3   = sizeof(WebSocketReceive3) - 1;	// (record-time: 273 bytes)

#endif
