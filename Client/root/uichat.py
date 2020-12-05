#search:
		btnChatLog = ui.Button()
		btnChatLog.SetParent(self)
		btnChatLog.SetUpVisual("d:/ymir work/ui/game/taskbar/Open_Chat_Log_Button_01.sub")
		btnChatLog.SetOverVisual("d:/ymir work/ui/game/taskbar/Open_Chat_Log_Button_02.sub")
		btnChatLog.SetDownVisual("d:/ymir work/ui/game/taskbar/Open_Chat_Log_Button_03.sub")
		btnChatLog.SetToolTipText(localeInfo.CHAT_LOG)
		btnChatLog.Hide()
		self.btnChatLog = btnChatLog

#add:
		self.btnEmojiInfo = ui.Button()
		self.btnEmojiInfo.SetParent(self)
		self.btnEmojiInfo.SetUpVisual("d:/ymir work/ui/game/taskbar/emoji.png")
		self.btnEmojiInfo.SetOverVisual("d:/ymir work/ui/game/taskbar/emoji_over_in.png")
		self.btnEmojiInfo.SetDownVisual("d:/ymir work/ui/game/taskbar/emoji_over_out.png")
		self.btnEmojiInfo.SetToolTipText("Emoji")
		self.btnEmojiInfo.SetEvent(lambda : self.__OpenInfoEmoji())
		self.btnEmojiInfo.Hide()

		self.InfoEmojiThinBoard = ui.ThinBoard()
		self.InfoEmojiThinBoard.SetSize(690, 110)
		self.InfoEmojiThinBoard.SetParent(self)
		self.InfoEmojiThinBoard.SetPosition(0, 0)
		self.InfoEmojiThinBoard.AddFlag('attach')
		self.InfoEmojiThinBoard.Hide()
		
		self.InfoEmojiImage = ui.ImageBox()
		self.InfoEmojiImage.SetParent(self.InfoEmojiThinBoard)
		self.InfoEmojiImage.SetPosition(5, 5)
		self.InfoEmojiImage.LoadImage("icon\emoji\yahoo\emoji_page_all.png")
		self.InfoEmojiImage.Show()
		
#search:
		self.Refresh()
		self.chatInputSet.RefreshPosition()
	
	def __del__(self):
		ui.Window.__del__(self)

#add:
	def __OpenInfoEmoji(self):
		if self.InfoEmojiThinBoard.IsShow():
			self.InfoEmojiThinBoard.Hide()
			systemSetting.SetHideEmojiInfo(not systemSetting.IsHideEmojiInfo())
			systemSetting.SaveConfig()
		else:
			self.InfoEmojiThinBoard.Show()
			systemSetting.SetHideEmojiInfo(0)
			systemSetting.SaveConfig()


#search:
	def Destroy(self):
		self.chatInputSet.Destroy()
		self.chatInputSet = None

#add:
		self.btnEmojiInfo = 0
		self.InfoEmojiThinBoard = 0
		

#search:
		self.btnChatLog.SetPosition(self.GetWidth() - 45-21, 2)
		self.btnChatLog.Show()

#add:
		self.btnEmojiInfo.SetPosition(self.GetWidth() - 30-21, -5)
		self.btnEmojiInfo.Show() #Show

		if not systemSetting.IsHideEmojiInfo():
			self.InfoEmojiThinBoard.Show()
			
#search:
	def CloseChat(self):
		chat.SetBoardState(self.chatID, chat.BOARD_STATE_VIEW)
		self.boardState = chat.BOARD_STATE_VIEW
		(x, y, width, height) = self.GetRect()
		chat.SetPosition(self.chatID, x + 10, y + self.EDIT_LINE_HEIGHT)
		self.SetSize(self.CHAT_WINDOW_WIDTH, 0)
		self.chatInputSet.Close()
		self.btnSendWhisper.Hide()
		self.btnChatLog.Hide()
		self.btnChatSizing.Hide()
		self.Refresh()

#add:
		self.btnEmojiInfo.Hide()
		self.InfoEmojiThinBoard.Hide()

#search:
	def RefreshBoardEditState(self):

		(x, y, width, height) = self.GetRect()
		(btnX, btnY) = self.btnChatSizing.GetGlobalPosition()

		self.xBar = x
		self.yBar = btnY
		self.widthBar = width
		self.heightBar = y - btnY + self.EDIT_LINE_HEIGHT
		self.curHeightBar = self.heightBar
		chat.SetPosition(self.chatID, x + 10, y)
		chat.SetHeight(self.chatID, y - btnY - self.EDIT_LINE_HEIGHT)

#add:
		self.InfoEmojiThinBoard.SetPosition(25, (y - btnY - self.EDIT_LINE_HEIGHT+126)*-1)
		
		
