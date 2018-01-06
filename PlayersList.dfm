object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1057#1087#1080#1089#1086#1082' '#1080#1075#1088#1086#1082#1086#1074
  ClientHeight = 632
  ClientWidth = 1048
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object AddBtn: TButton
    Left = 864
    Top = 128
    Width = 137
    Height = 41
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1075#1088#1086#1082#1072
    Enabled = False
    TabOrder = 0
    OnClick = AddBtnClick
  end
  object SetFileBtn: TButton
    Left = 864
    Top = 64
    Width = 137
    Height = 41
    Caption = #1042#1099#1073#1088#1072#1090#1100' '#1092#1072#1081#1083
    TabOrder = 1
    OnClick = SetFileBtnClick
  end
  object PlayersListGd: TStringGrid
    Left = 5
    Top = 0
    Width = 810
    Height = 627
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    ColCount = 6
    DoubleBuffered = True
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
    ParentDoubleBuffered = False
    TabOrder = 2
    ColWidths = (
      64
      64
      64
      64
      64
      64)
    RowHeights = (
      24)
  end
  object EditBtn: TButton
    Left = 864
    Top = 192
    Width = 137
    Height = 41
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    Enabled = False
    TabOrder = 3
    OnClick = EditBtnClick
  end
  object DeleteBtn: TButton
    Left = 864
    Top = 256
    Width = 137
    Height = 41
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Enabled = False
    TabOrder = 4
    OnClick = DeleteBtnClick
  end
end
