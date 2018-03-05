        // https://www.codechef.com/MARCH18B/problems/MINEAT/
        #include <iostream>
        #include <set>
        #include <map>
        #include <algorithm>
        #include <climits>
        using namespace std;
         
        int main()
        {
            #ifndef ONLINE_JUDGE
            freopen("inp.txt","r",stdin);
            freopen("out.txt", "w", stdout);
            #endif
            int t;
            cin>>t;
            while(t--)
            {
                int n;
                cin>>n;
                int h;
                cin>>h;
                int arr[n];
                for(int i=0; i<n; i++)
                    cin>>arr[i];
                //int j=*min_element(arr,arr+n);
                int lm=*max_element(arr,arr+n);
                int mn=INT_MAX;
                int left=1, right=lm, mid=(left+right)/2;
                while(left<=right)
                {
                    int sum=0,k=0;
                    mid=(left+right)/2;
                    for(; k<n; k++)
                    {
                        sum+=(arr[k]/mid + ((arr[k]%mid)?1:0));
                        if(sum>h)
                        {
                            
                            break;
                        }
                    
                    }

                    if(sum>h)
                        {
                            left=mid+1;
                            
                        }
                    else
                        {
                            right=mid-1;
                        }
                    if(k==n)
                    mn=min(mid,mn);
                    //cout<<left<<right<<" ";
                
               }
                cout<<mn<<endl;;
            }
            return 0;
        }  
