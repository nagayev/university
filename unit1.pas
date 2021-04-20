unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Memo1: TMemo;
    procedure Button1Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
type link=^item;
  item=record
    v:link;
    g:integer;
  end;
var
  p,b: link;
  i,mult:integer;
begin
  {
    Дан цепной односвязный список, элементами которого являются целые
  числа. В односвязном списке найти: произведение двузначных положительных
  чисел.
  }
  b:=nil;
  mult:=1;
  for i:=0 to memo1.lines.count-1 do begin
    new(p);
    p^.g:=strtoint(Memo1.lines[i]);
    if (p^.g>=10) and (p^.g<=99) then
       mult:=mult*p^.g;
    p^.v:=b;
    b:=p;
  end;
  Edit1.text:=inttostr(mult);
end;
end.

