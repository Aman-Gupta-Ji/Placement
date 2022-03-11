import java.util.*;
import java.io.*;
public class HarryPotterGraph {
    private static int dfs(List<List<Integer>> graph, List<List<Integer>> lra, List<Boolean> visited ,int n, int k, int points, int pos, int count) {
        if(points==k)
            return 1;
        if(points>k)
            return 0;
        if(count==n)
            return 0;
        List<Integer> temp;
        int l, r, a;
        int d;
        int ans=0;
        for(Integer des: graph.get(pos)) {
            d=des.intValue();
            temp=lra.get(d);
            l=temp.get(0).intValue();
            r=temp.get(1).intValue();
            a=temp.get(2).intValue();
            if(visited.get(d)==false) {
                if(points>r||points<l)
                    continue;
                visited.set(d,true);
                ans+=dfs(graph,lra,visited,n,k,points+a,d,count+1);
                visited.set(d,false);
            }
            else
                ans+=dfs(graph,lra,visited,n,k,a,d,count);
        }
        return ans;
    }
    private static int findans(List<List<Integer>> graph, List<List<Integer>> lra, List<Boolean> visited ,int n, int k) {
        int ans=0;
        for(int start=0;start<n;start++) {
            visited.set(start,true);
            ans+=dfs(graph,lra,visited,n,k,lra.get(start).get(2).intValue(),start,1);
            visited.set(start,false);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); 
        // Scanner has functions to read ints, longs, strings, chars, etc.
        int n, m, k;
        int res, i;
        int l, r, a;
        int s, d;
        for (int z = 1; z <= t; ++z) {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            List<List<Integer>> graph=new ArrayList<>();
            List<List<Integer>> lra=new ArrayList<>();
            List<Boolean> visited=new ArrayList<>();
            for(i=0;i<n;i++) {
                l=in.nextInt();
                r=in.nextInt();
                a=in.nextInt();
                graph.add(new ArrayList<>());
                visited.add(true);
                lra.add(Arrays.asList(new Integer[]{l,r,a}));
            }
            for(i=0;i<m;i++) {
                s=in.nextInt();
                d=in.nextInt();
                graph.get(s).add(d);
                graph.get(d).add(s);
            }
            res=findans(graph,lra,visited,n,k);
            System.out.println("Case #" + z + ": " + res);
        }
    }
}