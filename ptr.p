program main (a); 
	var c : ^integer;
	var a : integer;
	var b : boolean;
begin
	a := 8;
	c := @a;
	a := ^c;
	write(a)
end.
