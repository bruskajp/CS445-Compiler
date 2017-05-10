program main (a); 
	var a : ^integer;
	var b : integer;
begin
	a := @b;
	b := ^a
end.
