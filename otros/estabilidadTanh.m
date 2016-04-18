epsilon=0.0001;
x=-1:epsilon:1;
for i=1:length(x)
a(i)=(x(i)-(x(i)+epsilon))/(x(i));
b(i)=(tanh(100*x(i))-tanh(100*(x(i)+epsilon)))/tanh(x(1));
end

% plot(x,a);
hold all
plot(x,b,'b','linewidth',2);